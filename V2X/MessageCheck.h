#pragma once
#include "SliceMessage.h"
#include "CommunicationNode.h"
 
/*
 *ÏûÏ¢¼ì²â
*/
//ÎóÂë¼ì²â
bool errorCheck(SliceMessage sMsg);

//¿É´ï¼ì²â
bool reachCheck(SliceMessage sMsg, CommunicationNode dest, list<CommunicationNode> communicationNodes);