/******************************************************************************
This source code is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.
*******************************************************************************/

#ifndef __TORUS2D_H__
#define __TORUS2D_H__

#include <vector>
#include "Topology.hh"
#include "TopologyConfiguration.hh"

namespace Analytical {
class Torus2D : public Topology {
 public:
  using TopologyConfigurations = TopologyConfiguration::TopologyConfigurations;

  /**
   * Construct a Torus2D topology.
   * Caveat: currently only support square one.
   *
   * @param configurations configuration for each dimension
   * @param npus_count total number of npus connected to this torus2D
   */
  Torus2D(
      const TopologyConfigurations& configurations,
      int npus_count) noexcept;

  Latency send(NpuId src_id, NpuId dest_id, PayloadSize payload_size) noexcept
      override;

 private:
  using Direction = int; // +1 for up/right, -1 for down/left

  NpuAddress npuIdToAddress(NpuId id) const noexcept override;
  NpuId npuAddressToId(const NpuAddress& address) const noexcept override;

  int width; // width of the torus, therefore (npus_count = width * width)
  int half_width; // 1/2 of the width, used for choosing direction

  /**
   * Compute which direction the index should move.
   *
   * @param src_index
   * @param dest_index
   * @return +1 if next_index = current_index + 1
   *         -1 if next_index = current_index - 1
   */
  Direction computeDirection(NpuId src_index, NpuId dest_index) const noexcept;

  /**
   * Translate npuId to row-col pair.
   * (In the code, each row-col coordinate is denoted as 'index')
   * @param id npuId
   * @return (row, col) tuple
   */
  std::pair<int, int> idToRowCol(NpuId id) const noexcept;

  /**
   * Translate (row, col) to NPU's ID.
   * @param row
   * @param column
   * @return npuId
   */
  NpuId rowColToId(int row, int column) const noexcept;

  /**
   * Compute the next index after taking a single step towards direction.
   *
   * @param current_index
   * @param direction direction to move
   * @return next_index after taking a step
   */
  int takeStep(int current_index, Direction direction) const noexcept;
};
} // namespace Analytical

#endif
