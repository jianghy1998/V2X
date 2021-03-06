#include "Sub_processManagement.h"
#include "MessageTransferManagement.h"
#include "DelieveQueue.h"
#include "constUtil.h"
#include "Sender.h"
#include "Receiver.h"

using namespace std;
void Sub_processManagement::sub_process(list<CommunicationNode> Cluster, Protocol &protocol, Channel &channel)
{
	//####################################################################
	//1. 消息发送过程
	//####################################################################
	cout << "发送消息：" << endl;
	Sender send = Sender(Cluster, protocol);
	send.send();
	cout << "Sub_processManagement:Cluster大小：" << Cluster.size() << endl;



	//####################################################################
	//2. 消息处理过程
	//####################################################################
	cout << "处理消息：" << endl;
	//1）初始化待送达队列
	queue<SliceMessage> * deQ = new queue<SliceMessage>;
	DelieveQueue *delieveQ = new DelieveQueue(*deQ);

	//根据簇的大小确定通信模拟次数
	int s = Cluster.size();
	int simulation_count = 0;
	if (s <= 5) {
		simulation_count = 20;
	}
	else if (s <= 10) {
		simulation_count = 7;
	}
	else if (s <= 15) {
		simulation_count = 4;
	}
	else if (s <= 20) {
		simulation_count = 3;
	}
	else if (s <= 35) {
		simulation_count = 2;
	}
	else {
		simulation_count = 1;
	}

	//2) 消息处理过程
	MessageTransferManagement msgTransferManagement;
	for (int i = 0; i < simulation_count; i++) {
		msgTransferManagement.messageTransferManagement(i, protocol, Cluster, *delieveQ, channel, simulation_count);
 	}
	
	//####################################################################
	//3. 消息接收过程
	//####################################################################

	cout << "接收消息：" << endl;
	Receiver receive = Receiver(Cluster, protocol);
	receive.receive();
}
