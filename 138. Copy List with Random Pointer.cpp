/*
  struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
*/
 
class Solution
{
public:
	RandomListNode *copyListOnlyNextPointers(RandomListNode *head,
					unordered_map<RandomListNode*, RandomListNode*>& sourceDestMap)
	{
		auto sourceNode = head;
		RandomListNode* destHead = NULL;
		RandomListNode* destNode = NULL;

		while (sourceNode)
		{
			auto newCreatedDestNode = new RandomListNode(sourceNode->label);
			sourceDestMap.insert({ sourceNode, newCreatedDestNode });

			if (!destHead)
			{
				destHead = newCreatedDestNode;
				destNode = destHead;
			}
			else
			{
				destNode->next = newCreatedDestNode;
				destNode = destNode->next;
			}
			sourceNode = sourceNode->next;
		}
		if (destHead)
		{
			destNode->next = NULL;
		}

		return destHead;
	}

	RandomListNode *copyRandomList(RandomListNode *head)
	{
		unordered_map<RandomListNode*, RandomListNode*> sourceDestMap;
		auto destHead = copyListOnlyNextPointers(head, sourceDestMap);
		auto sourceNode = head;
		auto destNode = destHead;
		
		while (destNode && sourceNode)
		{
			if (sourceNode->random)
			{
				auto destNodeRandom = (sourceDestMap.find(sourceNode->random))->second;
				destNode->random = destNodeRandom;
			}
			else
			{
				destNode->random = NULL;
			}
			destNode = destNode->next;
			sourceNode = sourceNode->next;
		}

		return destHead;
	}
};
