/*
 * kernel_descriptor.h
 *
 *  Created on: 14 Jun 2016
 *      Author: muhammed
 */

#ifndef KERNEL_DESCRIPTOR_H_
#define KERNEL_DESCRIPTOR_H_

#include "aux_functions.hpp"
#include <typeinfo>

template<typename T>
class kernel{
  // basic parameters
  unsigned size0, size1, size2;
  unsigned offset0, offset1, offset2;
  unsigned wg_size0, wg_size1, wg_size2;
  unsigned nParams, nDim;
  //calculated parameters
  unsigned size, n_wg0, n_wg1, n_wg2;
  unsigned wg_size;
  unsigned nWF_WG;
  unsigned start_addr;
  //extra info
  unsigned problemSize, dataSize;
  T *position, *new_position_arm, *new_position_fgpu;
  T *velocity, *new_velocity_arm, *new_velocity_fgpu;
  T epsSqr, deltaTime;
  void compute_descriptor();
public:
  kernel(unsigned max_size);
  ~kernel();
  void download_code();
  void download_descriptor();
  void prepare_descriptor(unsigned int Size);
  unsigned get_problemSize();
  unsigned compute_on_ARM(unsigned int n_runs);
  void initialize_memory();
  unsigned compute_on_FGPU(unsigned n_runs, bool check_results);
  void check_FGPU_results();
  void print_name();

};




#endif /* KERNEL_DESCRIPTOR_H_ */
