/*
 * Copyright (C) 2011 Daniel Himmelein
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mindroid/os/Thread.h"
#include "mindroid/util/Assert.h"

namespace mindroid {

Thread::Thread() :
        mRunnable(this),
        mThreadId(NULL),
        mInterrupted(false) {
    mThread.pthread = &Thread::exec;
    mThread.tpriority = osPriorityNormal;
    mThread.instances = 1;
    mThread.stacksize = 0;
}

Thread::Thread(Runnable* runnable) :
        mRunnable(runnable),
        mThreadId(NULL),
        mInterrupted(false) {
    mThread.pthread = &Thread::exec;
    mThread.tpriority = osPriorityNormal;
    mThread.instances = 1;
    mThread.stacksize = 0;
}

bool Thread::start() {
    if (mRunnable != NULL) {
        mThreadId = osThreadCreate(&mThread, this);
    }
    return (mThreadId != NULL);
}

void Thread::sleep(uint32_t milliseconds) {
    osDelay(milliseconds);
}

void Thread::join() const {
    bool notYetImplemented = true;
    Assert::assertTrue(!notYetImplemented);
}

void Thread::exec(const void* args) {
    Thread* const self = (Thread*) args;
    self->mRunnable->run();
}

void Thread::interrupt() {
    mInterrupted = true;
}

bool Thread::isInterrupted() const {
    return mInterrupted;
}

} /* namespace mindroid */
