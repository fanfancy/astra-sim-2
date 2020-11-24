/******************************************************************************
This source code is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.
*******************************************************************************/

#include "MyPacket.hh"
namespace AstraSim {
MyPacket::MyPacket(int preferred_vnet, int preferred_src, int preferred_dest) {
  this->preferred_vnet = preferred_vnet;
  this->preferred_src = preferred_src;
  this->preferred_dest = preferred_dest;
}
void MyPacket::set_notifier(Callable* c) {
  notifier = c;
}
void MyPacket::call(EventType event, CallData* data) {
  cycles_needed = 0;
  if (notifier != NULL)
    notifier->call(EventType::General, NULL);
}
} // namespace AstraSim