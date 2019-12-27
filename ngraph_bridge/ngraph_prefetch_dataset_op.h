/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

/*******************************************************************************

This file is a copy of
Github repository: https://github.com/tensorflow/tensorflow
Revision: 87989f69597d6b2d60de8f112e1e3cea23be7298
File: tensorflow/core/kernels/data/prefetch_dataset_op.h

*******************************************************************************/

/*******************************************************************************
 * Copyright 2019 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/

#ifndef NGRAPH_TENSORFLOW_CORE_KERNELS_DATA_PREFETCH_DATASET_OP_H_
#define NGRAPH_TENSORFLOW_CORE_KERNELS_DATA_PREFETCH_DATASET_OP_H_

#include "ngraph_bridge/prefetch_autotuner.h"
#include "tensorflow/core/framework/dataset.h"
using namespace std;

namespace tensorflow {
namespace data {

class NGraphPrefetchDatasetOp : public UnaryDatasetOpKernel {
 public:
  explicit NGraphPrefetchDatasetOp(OpKernelConstruction* ctx)
      : UnaryDatasetOpKernel(ctx) {
    cout<<"Constructor NGraphPrefetchDatasetOp Start "<<name()<<endl;
    if (ctx->HasAttr("slack_period")) {
      OP_REQUIRES_OK(ctx, ctx->GetAttr("slack_period", &slack_period_));
    }
    cout<<"Constructor NGraphPrefetchDatasetOp End "<<name()<<endl;
  
  }

 protected:
  void MakeDataset(OpKernelContext* ctx, DatasetBase* input,
                   DatasetBase** output) override;

 private:
  class Dataset;
  int64 slack_period_ = 0;
};

}  // namespace data
}  // namespace tensorflow

#endif  // NGRAPH_TENSORFLOW_CORE_KERNELS_DATA_PREFETCH_DATASET_OP_H_
