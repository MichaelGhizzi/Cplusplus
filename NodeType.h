class NodeType {

public:
	NodeType(int = 0);  		// constructor with default value for info field data
	int info;            
	NodeType * nextPtr; 		// pointer to next node in the list
};

// Constructor
NodeType::NodeType(int data)
{
	info = data;
	nextPtr = 0;
}
