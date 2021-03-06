#pragma once
#ifndef RECEIVER_H
#define RECEIVER_H

#include "CommunicationNode.h"
#include "Protocol.h"
#include "Message.h"
#include "SliceMessage.h"
#include "SendQueue.h"
#include <queue>

/*
 *消息接收过程
*/
class Receiver {
public:
	list<CommunicationNode> *objectManager;//所有通信节点
	Protocol *protocol;//协议栈对象

public:
	Receiver();
	Receiver(std::list<CommunicationNode> &lc, Protocol &p);
	~Receiver();
	void receive();//控制流程
	std::list<SliceMessage> * getFromRQuene(ReceiveQueue &rq);//从接收队列获取分片消息
	std::list<Message> * sendToProtocol(Protocol &p, std::list<SliceMessage> &lsm);//将分片消息送入协议栈处理
};

#endif