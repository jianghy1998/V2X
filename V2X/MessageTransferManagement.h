#pragma once
#include "SendQueue.h"
#include "SliceMessage.h"
#include "CommunicationNode.h"
#include "DelieveQueue.h"
#include "Protocol.h"
#include "Channel.h"
#include <list>
//#########################################################
//消息处理模块，发送与接收模块的中间模块
//发送队列->待送达队列->接收队列的过程
//#########################################################
class MessageTransferManagement
{
public: 
	//消息处理模块主方法，调用该方法可以模拟消息的处理过程
	void messageTransferManagement(int index, Protocol &protocol, list<CommunicationNode> &communicationNodes, DelieveQueue &dQueue, Channel &channel, int simulation_count);
	//消息选择功能，从非空的发送队列中随机选择7个发送队列的消息头送入待送达队列
	void seleceMessage(std::list<CommunicationNode> &communicationNodes, DelieveQueue &dQueue);
	//物理信道模拟功能，将sMsg进行物理信道相关模拟
	void channelSimulation(SliceMessage &sMsg, int index, list<CommunicationNode> communicationNodes, Channel &channel, int simulation_count);

private:
	//获取所有非空的发送队列
	list<CommunicationNode>* getNonemptySendQueueList(std::list<CommunicationNode> communicationNodes);
	//将当前消息送到待送达队列
	bool sendToDelieveQueue(SliceMessage sMsg, DelieveQueue &dQueue);
	//获取所有接收节点
	std::list<CommunicationNode> getAllReceiveNodes(SliceMessage sMsg, std::list<CommunicationNode> communicationNodes);
	//将消息送到接收队列
	void sendToReceiveQueue(SliceMessage sMsg, list<CommunicationNode> &communicationNodes);
	//检查消息是否误码
	bool checkErrorMessage(SliceMessage sMsg);
	//所有发送队列的退避处理
	void backOffAll(list<CommunicationNode> &communicationNode, Protocol &protocol);
};