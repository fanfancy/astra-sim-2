/******************************************************************************
This source code is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.
*******************************************************************************/

#include "TopologyConfiguration.hh"

using namespace Analytical;

TopologyConfiguration::TopologyConfiguration(
    Latency link_latency,
    Bandwidth link_bandwidth,
    Latency nic_latency,
    Latency router_latency,
    Latency hbm_latency,
    Bandwidth hbm_bandwidth,
    double hbm_scalar) noexcept
    : link_latency(link_latency),
      link_bandwidth(link_bandwidth),
      nic_latency(nic_latency),
      router_latency(router_latency),
      hbm_latency(hbm_latency),
      hbm_bandwidth(hbm_bandwidth),
      hbm_scalar(hbm_scalar) {}

TopologyConfiguration::Latency TopologyConfiguration::getLinkLatency()
    const noexcept {
  return link_latency;
}

TopologyConfiguration::Bandwidth TopologyConfiguration::getLinkBandwidth()
    const noexcept {
  return link_bandwidth;
}

TopologyConfiguration::Latency TopologyConfiguration::getNicLatency()
    const noexcept {
  return nic_latency;
}

TopologyConfiguration::Latency TopologyConfiguration::getRouterLatency()
    const noexcept {
  return router_latency;
}

TopologyConfiguration::Latency TopologyConfiguration::getHbmLatency()
    const noexcept {
  return hbm_latency;
}

TopologyConfiguration::Bandwidth TopologyConfiguration::getHbmBandwidth()
    const noexcept {
  return hbm_bandwidth;
}

double TopologyConfiguration::getHbmScalar() const noexcept {
  return hbm_scalar;
}
