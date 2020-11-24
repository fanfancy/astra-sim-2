/******************************************************************************
This source code is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.
*******************************************************************************/

#ifndef __SWITCH_HH__
#define __SWITCH_HH__

#include <vector>
#include "Topology.hh"
#include "TopologyConfiguration.hh"

namespace Analytical {
class Switch : public Topology {
 public:
  using TopologyConfigurations = TopologyConfiguration::TopologyConfigurations;

  /**
   * Constrct a switch.
   * @param configurations configuration for each dimensino
   *              - Simple switch has only 1 dim
   * @param npus_count number of npus connected to the switch
   */
  Switch(const TopologyConfigurations& configurations, int npus_count) noexcept;

  Latency send(NpuId src_id, NpuId dest_id, PayloadSize payload_size) noexcept
      override;

 private:
  NpuAddress npuIdToAddress(NpuId id) const noexcept override;
  NpuId npuAddressToId(const NpuAddress& address) const noexcept override;

  int switch_id; // id of the switch node
};
} // namespace Analytical

#endif
