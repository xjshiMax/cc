/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_RUNNABLE_H_
#define _BGCC2_RUNNABLE_H_

#include "bgcc_common.h"
#include "shareable.h"

namespace bgcc {

    class Runnable : public Shareable {
    public:
        virtual int32_t operator()(const bool* isstopped, void* param = NULL) = 0;
        virtual ~Runnable() { }
    };
}
#endif // _BGCC2_RUNNABLE_H_

