#pragma once
#include <list>
#include "CommunicationNode.h"
#include "Protocol.h"
#include "Channel.h"

/*
 *通信模拟中一个簇的模拟过程
*/
class Sub_processManagement {
	//在每一个簇内的消息处理过程
public:
	void sub_process(list<CommunicationNode> Cluster, Protocol &protocol, Channel &channel);
};
