#include "Message.h"

Message::Message()
{
}

Message::Message(long msgID, long sa, long da, int sz)
{
	MessageID = msgID;
	SourceAddress = sa;
	DestinationAddress = da;
	Size = sz;
}

Message::~Message()
{
}

long Message::getMessageID()
{
	return MessageID;
}

long Message::getSourceAddress()
{
	return SourceAddress;
}

long Message::getDestinationAddress()
{
	return DestinationAddress;
}

int Message::getSize()
{
	return Size;
}

int Message::getMessageType()
{
	return MessageType;
}

int Message::getTransmissionType()
{
	return TransmissionType;
}

void Message::setMessageID(long id)
{
	MessageID = id;
}

void Message::setSourceAddress(long sourceAddress)
{
	SourceAddress = sourceAddress;
}

void Message::setDestinationAddress(long destinationAddress)
{
	DestinationAddress = destinationAddress;
}

void Message::setSize(int size)
{
	Size = size;
}

void Message::setMessageType(int messageType)
{
	MessageType = messageType;
}

void Message::setTransmissionType(int transmissionType)
{
	TransmissionType = transmissionType;
}
