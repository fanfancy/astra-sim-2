/******************************************************************************
This source code is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.
*******************************************************************************/

#ifndef __TOPOLOGYCONFIGURATION_HH__
#define __TOPOLOGYCONFIGURATION_HH__

#include <vector>

namespace Analytical {
struct TopologyConfiguration {
 public:
  using Latency = double; // latency in ns
  using Bandwidth = double; // bandwidth in GB/s (= B/ns)
  using PayloadSize = int; // payload size in bytes
  using TopologyConfigurations =
      std::vector<TopologyConfiguration>; // Topology configurations for each
                                          // dimension

  TopologyConfiguration(
      Latency link_latency,
      Bandwidth link_bandwidth,
      Latency nic_latency,
      Latency router_latency,
      Latency hbm_latency,
      Bandwidth hbm_bandwidth,
      double hbm_scalar) noexcept;

  Latency getLinkLatency() const noexcept;
  Bandwidth getLinkBandwidth() const noexcept;
  Latency getNicLatency() const noexcept;
  Latency getRouterLatency() const noexcept;
  Latency getHbmLatency() const noexcept;
  Bandwidth getHbmBandwidth() const noexcept;
  double getHbmScalar() const noexcept;

 private:
  Latency link_latency;
  Bandwidth link_bandwidth;
  Latency nic_latency;
  Latency router_latency;
  Latency hbm_latency;
  Bandwidth hbm_bandwidth;
  double hbm_scalar;
};
} // namespace Analytical

#endif
