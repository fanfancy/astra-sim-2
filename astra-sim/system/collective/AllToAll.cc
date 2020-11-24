/******************************************************************************
This source code is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.
*******************************************************************************/

#include "AllToAll.hh"
namespace AstraSim {
AllToAll::AllToAll(
    ComType type,
    int id,
    int layer_num,
    RingTopology* allToAllTopology,
    int data_size,
    RingTopology::Direction direction,
    PacketRouting routing,
    InjectionPolicy injection_policy,
    bool boost_mode)
    : Ring(
          type,
          id,
          layer_num,
          allToAllTopology,
          data_size,
          direction,
          routing,
          injection_policy,
          boost_mode) {
  this->name = Name::AllToAll;
  this->enabled = true;
  if (boost_mode) {
    this->enabled = allToAllTopology->is_enabled();
  }
  switch (routing) {
    case PacketRouting::Hardware:
      parallel_reduce = nodes_in_ring - 1;
      break;
    case PacketRouting::Software:
      parallel_reduce = 1;
      break;
  }
}
int AllToAll::get_non_zero_latency_packets() {
  if (((RingTopology*)logicalTopology)->dimension !=
      RingTopology::Dimension::Local) {
    return parallel_reduce * 1;
  } else {
    return (nodes_in_ring - 1) * parallel_reduce * 1;
  }
}
void AllToAll::process_max_count() {
  if (remained_packets_per_max_count > 0)
    remained_packets_per_max_count--;
  if (remained_packets_per_max_count == 0) {
    max_count--;
    if (id == 0) {
      // std::cout<<"max count is now: "<<max_count<<"stream count is:
      // "<<stream_count<<" , free_packets: "<<free_packets<<std::endl;
    }
    release_packets();
    remained_packets_per_max_count = 1;
    if (routing == PacketRouting::Hardware) {
      current_receiver = ((RingTopology*)logicalTopology)
                             ->get_receiver_node(current_receiver, direction);
      if (current_receiver == id) {
        current_receiver = ((RingTopology*)logicalTopology)
                               ->get_receiver_node(current_receiver, direction);
      }
      current_sender = ((RingTopology*)logicalTopology)
                           ->get_sender_node(current_sender, direction);
      if (current_sender == id) {
        current_sender = ((RingTopology*)logicalTopology)
                             ->get_sender_node(current_sender, direction);
      }
    }
  }
}
void AllToAll::run(EventType event, CallData* data) {
  if (event == EventType::General) {
    free_packets += 1;
    if (comType == ComType::All_Reduce && stream_count <= parallel_reduce) {
      if (total_packets_received < parallel_reduce) {
        return;
      }
      for (int i = 0; i < parallel_reduce; i++) {
        ready();
      }
      iteratable();
    } else {
      ready();
      iteratable();
    }
  } else if (event == EventType::PacketReceived) {
    total_packets_received++;
    insert_packet(NULL);
  } else if (event == EventType::StreamInit) {
    for (int i = 0; i < parallel_reduce; i++) {
      insert_packet(NULL);
    }
  }
}
} // namespace AstraSim