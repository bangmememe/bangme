
int stack[100];
int tos;          // top of stack

void push(int data)
{
    stack[tos] = data;
    ++tos;      // tos = tos + 1;
}
int pop(void)
{
    --tos;
    return stack[tos];
}
