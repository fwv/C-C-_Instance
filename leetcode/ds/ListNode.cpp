using namespace std;

class ListNode
{   
    public:
        ListNode()=default;
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next() {}
};