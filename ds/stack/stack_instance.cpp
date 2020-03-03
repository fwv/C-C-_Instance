using namespace std;
#include<iostream>
#include<stack>
#include<queue>
#include<string>

static int NUM = 1;
static int OP = 2;
static int RIGHT_BRACKET = 3;
static int LEFT_BRACKET = 4;

struct elmt{
    int op;
    char c;
    int type;
};

stack<elmt> op_stack;
queue<elmt> prepare;
queue<elmt> postfix;

string postfix_expression(string str) {
    //prepare,adapt data type
    elmt e;
    for(int i = 0;i<str.size();i++) {
        char a = str[i];
        if(a=='+' || a=='-') {
            e.type = OP;
            e.op = 1;
        }else if(a=='*' || a=='/') {
            e.type = OP;
            e.op = 2;
        }else if(a=='(') {
            e.type = LEFT_BRACKET;
            e.op = -1;
        }else if(a==')') {
            e.type = RIGHT_BRACKET;
            e.op = -1;
        }else{
            e.type = NUM;
            e.op = -1;
        }
        e.c = a; 
        prepare.push(e);
    }

    while(!prepare.empty()) {
       elmt e = prepare.front();
       if(e.type == NUM) {
           postfix.push(e);
       }else if(e.type == OP) {
           if(!op_stack.empty()) {
            while(!op_stack.empty() && e.op <= op_stack.top().op) {
                     postfix.push(op_stack.top());
                     op_stack.pop();
                }
           }
           op_stack.push(e);
       }else if(e.type == LEFT_BRACKET){
           op_stack.push(e);
       }else if(e.type == RIGHT_BRACKET) {
           while(op_stack.top().type != LEFT_BRACKET) {
               postfix.push(op_stack.top());
               op_stack.pop();
           }
           //remove '('
           op_stack.pop();
       }
       prepare.pop();
    }
    //add remain op
    while(!op_stack.empty()) {
        postfix.push(op_stack.top());
        op_stack.pop();
    }

    string postfix_str;
    int size = postfix.size();
    for(int i = 0; i < size; i++) {
        char a = postfix.front().c;
        postfix_str[i] = a;
        postfix.pop();
    }   
    return postfix_str;
}

void stack_instance() {
    //string str = "7*(3+5)+2";
    string str;
    cout<<"please input infix expression(could contain brackets): ";
    cin>>str;
    string result = postfix_expression(str);
    cout<<"postfix expression is: "<<result.c_str()<<endl;
}