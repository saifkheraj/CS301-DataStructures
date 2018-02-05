
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>

using namespace std;

template <class Type>
struct Node
{
	Type data;
	Node<Type> *next;
};

template <class Type>
class stack
{
	private:
		Node <Type> *Top;
		int stacklength;
	public:
		stack();
		~stack();		
		bool isEmpty()const;
		void push(Type item);	
		Type pop();
		Type top()const;
};


template <class Type>
stack<Type>::stack()
{
	Top=NULL;
	stacklength=0;
}

template <class Type>
stack<Type>::~stack()
{
	Node<Type> *temp;
	while(Top!=NULL)
	{
		//free memory
		temp=Top;
		Top=Top->next;
		delete temp;
	}
}

template <class Type>
bool stack<Type>::isEmpty()const
{
	return (Top==NULL);
}

template <class Type>
void stack<Type>::push(Type item)
{
	//will be inserted at the stack top
	//we make a new node, insert data into it, and point it to the top to link 		//it to the node that was at the top before, then make Top point to the 	//newNode
	Node<Type> *NewNode=new Node<Type>;
	NewNode->data=item;
	NewNode->next=Top;
	Top=NewNode;
	stacklength++;
}

template <class Type>
Type stack<Type>::pop()
{
	if(Top==NULL)
	{
		cout<<"empty"<<endl;
	}
	else
	{
		Type value;
		Node<Type> *temp=Top;
		value=Top->data;
		Top=Top->next;
		delete temp;
		
		stacklength--;
		
		return value;
	}
}

template <class Type>
Type stack<Type>::top()const
{
	if(Top!=NULL)
	{
		return Top->data;
	}
}

/*---end of stack ---*/

bool isOperand(char str);
bool isOperator(char str);
bool prcd(char operator1,char operator2);
double oper(char symbol,double operator1,double operator2);
double evaluate(char expression[],stack<double> &s2);
void inFixtoPostFix(stack<char>& s1,char str[], char postFix[]);
void inFixtoPreFix(char str[],char preFix[],stack<char>& s1);
void reverse(char temp[]);
double evaluatePrefix(char expression[],stack<double> &s2);
void variableToValue(char pre_fix_string[],char value_str[]);


int main()
{
	stack<char> stack1;//this stack is used for postfix conversion putting symbols into this stack helps in conversion
	stack<double> evaluation;//this stack is used for evaluation 
	
	const int MAXSIZE=100;
	char str[MAXSIZE];//str stores infix given to us by user
	
	char post_fix_string[MAXSIZE];//this string stores postfix conversion
	char pre_fix_string[MAXSIZE];//this string stores prefix
	
	
	
	
	
	//main menu
	int option;//use for menu selection
	char sentinal;//used as a sentinal in do while loop
	char value_str[MAXSIZE];//used for variable expression, stores value in place of variable
	char variable_str[MAXSIZE];
	do
	{
		cout<<"---------WELCOME TO THE INFIX POSTFIX PREFIX CALCULATOR-------------"<<endl;
		cout<<"Please choose the following options for infix conversion"<<endl;
		cout<<"1. Enter Infix Expression in the variable form"<<endl;
		cout<<"2. Enter Infix Expression in the value form"<<endl;
		
		cin>>option;
		
		switch(option)
		{
			case 1:
				cout<<"Enter an infix expression in Variables: ";
				cin.ignore();
				cin.getline(str,MAXSIZE);//store value in str
				variableToValue(str,value_str);//convert variable to user input value of particular variable

				
				inFixtoPostFix(stack1,value_str, post_fix_string);//convert value_str from infix to postfix
				inFixtoPreFix(value_str,pre_fix_string,stack1);//convert value_str from infix to prefix
				
				inFixtoPostFix(stack1,str, variable_str);//convert infix to postfix in variables
				cout<<"Postfix Expression: "<<variable_str<<" = "<<evaluate(post_fix_string,evaluation)<<endl;
				
				memset(&variable_str[0], 0, sizeof(variable_str));//clear variable_str so that it can store prefix part
				inFixtoPreFix(str,variable_str,stack1);//convert infix to prefix in variables
				cout<<"Prefix Expression: "<<variable_str<<" = "<<evaluatePrefix(pre_fix_string,evaluation)<<endl;	
					
				break;
				
			case 2:	
				cout<<"Enter an infix expression in Value: ";
				cin.ignore();
				cin.getline(str,MAXSIZE);//store value in str
				
				inFixtoPostFix(stack1,str, post_fix_string);
				inFixtoPreFix(str,pre_fix_string,stack1);
				
				cout<<"Postfix Expression: "<<post_fix_string<<" = "<<evaluate(post_fix_string,evaluation)<<endl;
				cout<<"Prefix Expression: "<<pre_fix_string<<" = "<<evaluatePrefix(pre_fix_string,evaluation)<<endl;
				
				break;
				
				
			default:
			
				cout<<"You entered an incorrect option"<<endl;
				break;	
		}
	
	cout<<"DO YOU WANT TO GO TO THE MAIN MENU AGAIN PRESS C OR ELSE PRESS ANY KEY TO EXIT"<<endl;
	cin>>sentinal;
	
	cout<<sentinal;
	}while(sentinal=='C' || sentinal=='c');
	
return 0;
}


bool isOperand(char str)
{
	//operand could be from 0-9 or A-z checking through characters function
	return (isalpha(str) || isdigit(str));
}

bool isOperator(char str)
{
	//these all are operators
	return (str=='+' or str=='-' or str=='/' or str=='*' or str=='$');
}

//return true if operator1 prcd is higher than operator2
bool prcd(char operator1,char operator2)
{
	//check if operator1 on stack has higher precedence than operator2
	//check all conditions for brackets
	if(operator1=='(' || operator2=='(')
		return false;
		
	else if(operator1==')')
		return false;
		
	else if(operator2==')')
		return true;
	//check + and - they evaluate from left to right so should return true
	
	else if( (operator1=='+' && operator2=='-') || (operator1=='-' && operator2=='+') )
		return true;
		
	else if((operator1=='+' && operator2=='+') || (operator1=='-' && operator2=='-'))
		return true;
		
	//+  or  - has lesser preceddence than * and /
	else if((operator1=='+' || operator1=='-') && (operator2=='/' || operator2=='*'))
	{
		return false;
	}
	//this has highest precedence 
	else if(operator1=='$')
	{
		if(operator2=='$')
			return false;
		else			
			return true;
	}
	//
	else if(operator1=='/' || operator1=='*')
	{
		if(operator2=='$') return false;
		else return true;
	}
	else
	{
		if((operator2=='$' || operator2=='/' or operator2=='*'))
		
			return false;
		else return true;
	}	
}			

//function to perform operation of two operators
double oper(char symbol,double operator1,double operator2)
{
	switch(symbol)
	{
		case '+':
			return (operator1+operator2);
			break;
		case '-':
			return (operator1-operator2);
			break;
		case '*':
			return (operator1*operator2);
			break;
		case '/':
			return (operator1/operator2);
			break;
		case '$':	
			return pow(operator1,operator2);
			break;
		default:
			cout<<"Illegal Operators"<<endl;
	}
}

//expression is postfix expression this is evaluate for postfix, 
double evaluate(char expression[],stack<double> &s2)
{
//atoi to convert character array to int
	char temp[10];
	int count=0;
	double operator1,operator2;
	double value;
	
	for(int i=0;expression[i]!='\0';i++)
	{
		if(isdigit(expression[i]))
		{
			temp[count]=expression[i];
			count++;
		}
		else if(isspace(expression[i]))
		{
			if(count>0)
			{
				temp[count]='\0';
				//now that we have got digits push to the stack
				s2.push(atoi(temp));
				count=0;
			}
		}
		else if(isOperator(expression[i]))
		{			
			operator2=s2.pop();
			
			operator1=s2.pop();
				
			value=oper(expression[i],operator1,operator2);
			
			s2.push(value);	
		}
	}
	
	return s2.top();
}

//s1 is the stack for operator, str is the infix, postfix string will be stored in postfix cstring
void inFixtoPostFix(stack<char>& s1,char str[], char postFix[])
{
	char symbol;
	char topSymbol;
	int count=0;
	int stringcount=0;
	int length=0;
	int pos=0;//position of postfix cstring
	for(int i=0;str[i]!='\0';i++)
	{
		//read symbol
		symbol=str[i];
		
		if(isOperand(symbol))
		{
			//add to the string
			if(stringcount==0 && length!=0 && count==0)
			{
				postFix[pos++]=' ';
				stringcount=0;
			}
			
			postFix[pos++]=str[i];
			count++;
			length++;	
		}
		else
		{
			if(count>0)
			{
				postFix[pos++]=' ';
				count=0;
				stringcount++;
			}
			while(!s1.isEmpty() && prcd(s1.top(),symbol))
			{
				//pop and add to the postfix string
				topSymbol=s1.pop();
				postFix[pos++]=topSymbol;
				postFix[pos++]=' ';
			}
			
			if(s1.isEmpty() || symbol!=')')
			{
				s1.push(symbol);//push symbol to the stack
				
			}
			else
				topSymbol=s1.pop();//discard parenthesis
		}
	}
	
	while(!s1.isEmpty())
	{
		topSymbol=s1.pop();
		postFix[pos++]=' ';
		postFix[pos++]=topSymbol;
	}
	
	postFix[pos++]='\0';
}

//str is the infix, preFix will be the changed string from infix to preFix, s1 is the stack for operator and calculation
void inFixtoPreFix(char str[],char preFix[],stack<char>& s1)
{	
	//reverse the str
	stack<char> temp;
	char reverseInfix[100];
	
	int k=0;
	int count;
	for(int i=strlen(str)-1;i>=0;i--)
	{
		reverseInfix[k]=str[i];
		k++;	
	}
	
	reverseInfix[k]='\0';
	
	bool flag=false;
	for(int j=0,i=0;reverseInfix[j]!='\0';j++,i++)
	{
		flag=false;
		while( isOperand(reverseInfix[j]) )
		{
		//push to the stack
			flag=true;
			temp.push(reverseInfix[j]);
			j++;
		}
		
		if(reverseInfix[j]==')')
			reverseInfix[j]='(';
		else if(reverseInfix[j]=='(')
			reverseInfix[j]=')';
		
		if(flag)
		{
			while(i<j)
			{
				reverseInfix[i]=temp.pop();
				i++;		
			}
		}
		
		if(reverseInfix[j]=='\0')
			break;
	}	
	
	//infix has been reversed and stored in reverseInfix, now need to do same thing as the procedure from infix to postfix
	
	char temp_str[100];
	inFixtoPostFix(s1,reverseInfix,temp_str);
	//cout<<temp_str<<endl;//1000 7 +
	
	int a=0;
	for(int i=strlen(temp_str)-1;i>=0;i--)
	{
		preFix[a]=temp_str[i];
		a++;
	}
	
	preFix[a]='\0';
	
	//put it correct
	for(int j=0,i=0;preFix[j]!='\0';j++,i++)
	{
		flag=false;
		while( isOperand(preFix[j]) )
		{
		//push to the stack
			flag=true;
			temp.push(preFix[j]);
			j++;
		}
			
		if(flag)
		{
			while(i<j)
			{
				preFix[i]=temp.pop();
				i++;
			}
		}
		
		if(preFix[j]=='\0')
			break;
	}	
}

//reverse temp cstring using stack
void reverse(char temp[])
{
//new way to reverse using stack
	stack<char> t;
	
	for(int i=0;temp[i]!='\0';i++)
	{
		t.push(temp[i]);
	}
	
	int k=0;
	while(!t.isEmpty())
	{
		temp[k]=t.pop();
		k++;	
	}
}



//take 2 parameters, expression is the prefix expression, s2 is the stack for evaluation storing result into it,returns result
double evaluatePrefix(char expression[],stack<double> &s2)
{
//atoi to convert character array to int
	char temp[10];
	int count=0;
	double operator1,operator2;
	double value;
	
	for(int i=strlen(expression)-1;i>=0;i--)
	{
	
		if(isdigit(expression[i]))
		{
			temp[count]=expression[i];
			count++;
		}
		else if(isspace(expression[i]))
		{
			if(count>0)
			{
				temp[count]='\0';
				
				reverse(temp);
				
				//now that we have got digits push to the stack
								
				s2.push(atoi(temp));
				
				count=0;
			}
		}
		else if(isOperator(expression[i]))
		{
		
			operator1=s2.pop();
			
			operator2=s2.pop();
			
			value=oper(expression[i],operator1,operator2);
			
			s2.push(value);	
		}
	}
	
	return s2.top();
}

void variableToValue(char pre_fix_string[],char value_str[])
{
	bool flag=false;
	char temp[100];
	int var;
	stack <char> temp_store;
	int a=0;
	int j=0;
	for(int i=0;pre_fix_string[i]!='\0';i++)
	{

			flag=false;
			while(isalpha(pre_fix_string[i]) )
			{
				temp[j]=pre_fix_string[i];
				
				j++;
				i++;
				flag=true;
			}
			
			if(flag)
			{
				temp[j]='\0';
				cout<<"Enter the value for "<<temp<<" : ";
				cin>>var;
				
				while(var>0)
				{
					int num=var%10;
					var=var/10;
					temp_store.push(char(num+'0'));
					
				}
				
				while(!temp_store.isEmpty())
				{
					value_str[a]=temp_store.top();
					temp_store.pop();
					a++;
				}
				
				
				j=0;
				memset(&temp[0], 0, sizeof(temp));//clear memory of char array
				i--;		
			}
			else
			{
					
				value_str[a]=pre_fix_string[i];
				
				a++;
		
			}
	
			if(pre_fix_string[i]=='\0') break;
	
	}
	
	value_str[a]='\0';
}
