#include <iostream>
#include <fstream>
#include <string>

#define DEF_SIZE 50
#define FILENAME "palindrome.txt"

using namespace std;

struct Stack
{
	string *data;
	unsigned last;
	unsigned size;
};

Stack *create (unsigned size = DEF_SIZE)
{
	Stack *new_stack = new Stack;
	new_stack -> data = new string[size];
	new_stack -> size = size;
	new_stack -> last = 0;
	return new_stack;
}

struct Queue
{
	Queue *next;
	string data;
};

Queue *q_element(string data) // create queue element
{
	Queue *n = new Queue;
	n -> data = data;
	n -> next = NULL;
	return n;
}

void enqueue(Queue *q, string data)
{
	Queue *p = q;
	Queue *n = q_element(data);
	while (p -> next != NULL)
		p = p -> next;
	p -> next = n;
}

Queue *dequeue(string &dest, Queue *q)
{
	dest = q -> data;
	return q -> next;
}

void printQ(Queue *q) // print queue
{
	Queue *p = q;
	while (p != NULL)
	{
		cout << p -> data;
		if (p->next != NULL)
			cout << " -> ";
		p = p -> next;
	}
	cout << endl;
}

void push (Stack *s, string what)
{
	if (s -> last < s -> size)
	{
		s -> data[s -> last] = what;
		s -> last++;
	}
	else
	{
		cout << "ERROR: stack is full" << endl;
	}
}

void pop (Stack *s)
{
	if (s -> last > 0)
	{
		string *str = new string;
		s -> data[--(s -> last)] = *str;
	}
	else
	{
		cout << "ERROR: stack is empty" << endl;
	}
}

bool isEmpty (Stack *s)
{
	if (s -> last > 0)
		return false;
	return true;
}

string top (Stack *s)
{
	if ( s -> last > 0)
	{
		return s -> data[(s -> last) - 1];
	}
	else
	{
		cout << "ERROR: stack is empty" << endl;
		return NULL;
	}
}

string show_n_del (Stack *s)
{
	string data = top(s);
	pop(s);
	return data;
}
Stack *fileToStack (string fname = FILENAME, unsigned size = DEF_SIZE)
{
	Stack *s = create(size);
	fstream input;
	input.open ((const char*)fname.c_str());
	while (!input.eof())
	{
		string output;
		input >> output;
		push (s, output);
	}
	return s;
}

string strRev (string str)
{
    string newstr (str.length(), ' ');
    for (int i = 0; i < str.length(); i++)
	{
        newstr[str.length() - 1 - i] = str[i];
    }
	newstr[str.length()] = NULL;
    return newstr;
}

bool isPalin (string str)
{
  	string rev = strRev(str);
    if (rev == str)
		return true;
    return false;
}

int main()
{
	int count = 0;
	cout << endl;

	Stack *s = fileToStack(FILENAME);
	Stack *queue = create(s -> size);

	while (!isEmpty(s))
		push(queue,show_n_del(s));
	
	delete s;

	Queue *q = q_element(""); // create empty queue #2

	while (!isEmpty(queue))
	{
		string c = show_n_del(queue);
		enqueue(q, c); // add to queue #2
	}
	
	q = q -> next; // remove initial pointer #2
	printQ(q);
	cout << endl;

	while (q != NULL) // while queue is not empty #2
	{
		string c;
		q = dequeue(c,q); // export from queue -- next avail. item #2
		if (isPalin(c))
			cout << c << " is palindrome - " << ++count << endl;
		else
			cout << c << " is not palindrome "<< endl;
	}

	cout << "\n" << count << " palindrome" << ((count == 1)?"":"s") << " found..." <<endl;
	cout << endl;

	delete queue;

	return 0;
}
