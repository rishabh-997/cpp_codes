/**
* Tries data structure
	if query == "ADD"  => adds string to data structure
	if query == "FIND" => finds frequency of strings with that prefix
*/

	struct node {
	    int freq;
	    node *child[26];

	    node() {
		freq = 0;
		for (auto &i : child)
		    i = nullptr;
	    }
	};

	int main() {
	    fastRead()
	    int t;
	    string query, str;
	    cin >> t >> ws;
	    node *root = new node();
	    while (t--) {
		node *temp;
		temp = root;
		cin >> query >> str;

		if (query == "add") {
		    for (auto x: str) {
		        int pos = x - 'a';
		        if (temp->child[pos] == nullptr) {
		            node *create = new node();
		            temp->child[pos] = create;
		        }
		        temp = temp->child[pos];
		        temp->freq++;
		    }
		} else {
		    int flag = 1;
		    for (auto x: str) {
		        int pos = x - 'a';
		        if (temp->child[pos] == nullptr) {
		            cout << 0 << "\n";
		            flag = 0;
		            break;
		        } else {
		            temp = temp->child[pos];
		        }
		    }
		    if (flag)
		        cout << temp->freq << "\n";
		}
	    }
	    return EXIT_SUCCESS;
	}
