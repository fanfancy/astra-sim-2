/******************************************************************************
This source code is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.
*******************************************************************************/

#ifndef __COMMON_HH__
#define __COMMON_HH__
#include "AstraNetworkAPI.hh"
namespace AstraSim {
#define CLOCK_PERIOD 1
typedef unsigned long long Tick;
enum class ComType {
  None,
  Reduce_Scatter,
  All_Gatehr,
  All_Reduce,
  All_to_All,
  All_Reduce_All_to_All
};
enum class CollectiveBarrier { Blocking, Non_Blocking };
enum class SchedulingPolicy { LIFO, FIFO, HIGHEST, None };
enum class InjectionPolicy {
  Infinite,
  Aggressive,
  SemiAggressive,
  ExtraAggressive,
  Normal
};
enum class PacketRouting { Hardware, Software };
enum class BusType { Both, Shared, Mem };
enum class StreamState {
  Created,
  Transferring,
  Ready,
  Executing,
  Zombie,
  Dead
};
enum class EventType {
  RendezvousSend,
  RendezvousRecv,
  CallEvents,
  PacketReceived,
  WaitForVnetTurn,
  General,
  TX_DMA,
  RX_DMA,
  Wight_Grad_Comm_Finished,
  Input_Grad_Comm_Finished,
  Fwd_Comm_Finished,
  Wight_Grad_Comm_Finished_After_Delay,
  Input_Grad_Comm_Finished_After_Delay,
  Fwd_Comm_Finished_After_Delay,
  Workload_Wait,
  Reduction_Ready,
  Rec_Finished,
  Send_Finished,
  Processing_Finished,
  Delivered,
  NPU_to_MA,
  MA_to_NPU,
  Read_Port_Free,
  Write_Port_Free,
  Apply_Boost,
  Stream_Transfer_Started,
  Stream_Ready,
  Consider_Process,
  Consider_Retire,
  Consider_Send_Back,
  StreamInit,
  StreamsFinishedIncrease,
  CommProcessingFinished,
  NotInitialized
};
} // namespace AstraSim
#endif
