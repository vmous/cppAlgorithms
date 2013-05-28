#include <iostream>
#include <string.h>
#include <stack>

int precedence(char ch)
{
    switch(ch)
    {
        case '(' : return 1;
        case ')' : return 2;
        case '+' :
        case '-' : return 3;
        case '*' :
        case '/' :
        case '%' : return 4;
        case '^' : return 5;
        default : return 0;
    }
}

void infix_to_postfix(char * representation)
{
    std::cout << "Infix: " << representation << std::endl;

    std::stack<char> postfix;
    std::stack<char> operators;

    char * r = representation;
    while (*r)
    {
        if (   *r != '+' &&
                *r != '-' &&
                *r != '*' &&
                *r != '/' &&
                *r != '^' &&
                *r != '(' &&
                *r != ')')
        {
            postfix.push(*r);
        }
        else
        {
            if (*r == '(')
                operators.push(*r);
            else if (*r == ')')
            {
                while (operators.top() != '(')
                {
                    char c = operators.top();
                    postfix.push(c);
                    operators.pop();
                }

                operators.pop();
            }
            else
            {
                if (!operators.empty())
                {
                    while (precedence(*r) <= precedence(operators.top()))
                    {
                        char c = operators.top();
                        postfix.push(c);
                        operators.pop();
                    }
                }
                operators.push(*r);
            }
        }

        r++;
    }

    while (!operators.empty())
    {
        char c = operators.top();
        postfix.push(c);
        operators.pop();
    }

    char * str_postfix = new char[postfix.size() + 1];
    int j = postfix.size();
    str_postfix[j--] = '\0';
    while (!postfix.empty())
    {
        str_postfix[j--] = postfix.top();
        postfix.pop();
    }

    std::cout << "Postfix: " << str_postfix << std::endl;

    std::cout << std::endl;
}

void infix_to_prefix()
{

}

int main(int argc, char ** argv)
{
    char representation[] = "(A+B*(Z-D*E*H+G)*K)/(E*B)";
    infix_to_postfix(representation);
}
