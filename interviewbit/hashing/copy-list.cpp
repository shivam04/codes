/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* og = A;
    RandomListNode* cl = NULL;
    RandomListNode *n;
    unordered_map<RandomListNode*, RandomListNode*> mp;
    while(og!=NULL){
        if(cl==NULL){
            cl = new RandomListNode(og->label);
            n = cl;
        }else{
            cl = new RandomListNode(og->label);
        }
        mp[og] = cl;
        og = og->next;
    }
    og = A;
    while (og != NULL)
    {
        cl = mp[og];
        cl->next = mp[og->next];
        cl->random = mp[og->random];
        og = og->next;
    }
    return n;
}