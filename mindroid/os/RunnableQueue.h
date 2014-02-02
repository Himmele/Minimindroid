/*
 * Copyright (C) 2014 Daniel Himmelein
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

#ifndef MINDROID_RUNNABLEQUEUE_H_
#define MINDROID_RUNNABLEQUEUE_H_

#include <stdint.h>
#include "mindroid/os/MessageQueue.h"
#include "mindroid/os/Message.h"
#include "mindroid/util/Utils.h"

namespace mindroid {

class MessageQueue;
class Runnable;

class RunnableQueue
{
public:
	RunnableQueue(MessageQueue& messageQueue);
	~RunnableQueue();
	bool enqueueRunnable(Runnable& runnable, uint64_t execTimestamp);
	Runnable* dequeueRunnable();
	bool removeRunnable(const Runnable* runnable);

private:
	Message mMessage;
	MessageQueue& mMessageQueue;

	friend class Looper;

	NO_COPY_CTOR_AND_ASSIGNMENT_OPERATOR(RunnableQueue)
};

} /* namespace mindroid */

#endif /* MINDROID_RUNNABLEQUEUE_H_ */