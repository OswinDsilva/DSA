
2025-03-28 22:45

Status: #Apt #Medium #Incomplete 

Tags: [[C++]] [[CS]] [[DSA]] 

# C++ STL

 Standard Template Library - <bits/stdc++.h>

# Components
## 1. Algorithms
1. Sort algorithm:
	**Syntax:**
	```c++
	// Sorting, where itr1 represents the first position to sort from itr2 represents the last position to sort until
	sort(itr1,itr2+1);

	// Example
	// For a vector v
	sort(v.begin(),v.end());

	// Sort in descending
	sort(itr1,itr2+1,greater<int>);

	// Sort in custom order, where comp is a comparator
	sort(itr1,itr2+1,comp)
	```
2. Permutations:
	- Algorithm to get permutations of a string
	- returns **`true`** if a next permutation exists; otherwise, it returns `false` when the sequence is already in its last lexicographical order.
	**Syntax:**
	```c++
	// itr1 is start position, itr2 is the last position.
	next_permutation(itr1,itr2+1)
	```
	Example:
	```c++
	// Getting all permutations of the string
	string s="123";
	do{
		cout<<s<<endl;
	} while(next_permutation(s.begin(), s.end()))

	// The algorithm only finds permutation in dictionary order. Hence it is important to start from the sorted version of the sequence if all permutations are required.
	// start with
	sorted(s.begin(),s.end());
	```
3. Max element:
	**Syntax:**
	```c++
	// Returns the max element in the iterator range ,inlcuding the lower iterator in the range and  excluding the upper iterator in the range
	max_element(itr1,itr2+1)
	```
4. Min element:
	 **Syntax:**
	```c++
	// Returns the min element in the iterator range ,inlcuding the lower iterator in the range and  excluding the upper iterator in the range
	min_element(itr1,itr2+1)
	```
## 2. Containers
1. Pairs:
	**Syntax:** 
	``` c++
	pair<dtype,dtype> name = {a,b};
	```
	- You can access the elements of a pair using name.first for the first element and name.second for the second element.
	- You can have pair as a datatype - Nesting pairs. In order to access values of nested pairs, you just chain the .first and .second commands. Ex: name.first.first
	- You can also create a array of pairs by just appending [] after the name.
2. Vectors:
	**Syntax:**
	```c++
	vector<dtype> v;
	```
	- A vector is a dynamic data structure. It can be thought of as a array of unfixed size.
	
	**Functions:**	
	- The functions under the main Functions heading are also applicable to vectors.
	```c++
	//Pre initializing a container using the "(size, number)"technique/method
	vector<int> v1(5,100);
	```
	- The above line creates a vector having 5 100s.
	- If the number is left empty, it may generate garbage values or zero values.
	- If just the size is given, container of that size is created. But this size is not fixed, i.e. it can be expanded.
	```c++
	// Copying containers using (container) technique/method
	vector<int> v2(v1);
	```
	- The vector v2 will also be initialized to 5 100 values.
	- This method only creates a copy not a reference.
	```c++
	//Accessing elements of a vector
	v[idx];
	v.at(idx);
	```
	- A vector can accessed normally just like an array.
3. List:
	**Syntax:**
	```c++
	list<dtype> name;
	```
	**Functions:**
	- The functions under the main Functions heading are also applicable to Lists.
	- ==**Push front function:**==
	```c++
	ls.push_front(ele);
	```
	- Emplace front function:
	```c++
	ls.emplace_front(ele);
		```
4. Deque:
	**Syntax:**
	```c++
	deque<dtype> name;
	```
	**Functions:**
	- The functions under the main Functions heading are also applicable to Deque.
	- Also the functions under list are also applicable.
	- ==**Pop front function:**==
	```c++
	// Pops the front element
	dq.pop_front()
	```
	- ==**Front function:**==
	``` c++
	// Returns reference to the fron element
	dq.front()
	```
5. Stack:
	- Stack is known as LIFO structure (Last in ,first out)
	**Syntax:**
	```c++
	stack<dtype> name;
	```
	**Functions:**
	- All stack operations(push, pop, top) have a time complexity of O(1).
	- **==Push function:==**
	```c++
	// Pushes the element to the front(top) of the stack
	st.push(ele);
	//Example
	stack<int> st;
	st.push(1) // {1}
	st.push(2) // {2,1}
	```
	- **==Emplace function:==**
	```c++
	// Similar to push
	st.emplace(ele);
	```
	- **==Top function:==**
	```c++
	// Returns the element at the top(front) of the stack without altering the stack
	st.top();
	```
	- The return value can be used as a reference or just a constant value.
	
	- ==**Pop function:**==
	```c++
	// Returns the element at the top of the stack and alters the stack
	st.pop();
	```
	- **==Empty function:==**
	```c++
	// Checks whether the stack is empty
	st.empty();
	```
	- **==Size function :==**
	```c++
	// Returns the size of the stack
	st.size();
	```
	- **==Swap function:==**
	```c++
	// Swaps two stacks
	st1.swap(st2);
	```
6. Queues:
	- Queue is a FIFO structure(First in First out)
	**Syntax:**
	```c++
	queue<dtype> name;
	```
	**Functions:**
	- Queue operations are also O(1).
	- **==Push function:==**
	```c++
	// Pushes an element to the back of the queue
	q.push(ele);
	//Example
	queue<int> q;
	q.push(1) // {1}
	q.push(2) // {1,2}
	```
	- ==**Emplace function:**==
	```C++
	// Similar to push
	q.emplace(ele);
	```
	- **==Back function:==**
	```c++
	// Returns the element at the 'back' of the queue
	q.back();
	```
	- The return value can be used as a reference or just a constant value.
	
	- **==Front function:==**
	```c++
	// Returns the element at the 'front' of the queue
	q.front();	
	```
	- The return value can be used as a reference or just a constant value.

	- **==Pop function:==**
	```c++
	// Returns the element at the 'front' of the queue and adjusts the stack
	q.pop()
	```
	- Also has swap, size and empty functions
7. Priority queue:
	- Elements are stored using a tree
	- Also called heaps
	**Syntax:**
	```c++
	priority_queue<dtype> name;
	```
	**Functions:**
	- ==**Push function:**==
	- log n
	```c++
	// Pushes the element to the top of the queue.
	pq.push(ele);
	```
	- It also arranges the queue in order of highest value
	- **==Top function:==**
	- O(1)
	```c++
	// Returns the largest element
	pq.top();
	```
	- **==Pop function:==**
	- log n
	```c++
	// Returns the largest element and alters the structure
	pq.pop();
	```
	- **==*Creating a minimum element priority queue(the top element is the small element)*==**
	```c++
	priority_queue<int, vector<int>, greater<int>> name:
	```
8. Set:
	- A container which has only unique values and are sorted.
	- If a value which already exists in the set is inserted, the value is ignored.
	**Syntax:**
	```c++
	set<dtype> name;
	```
	**Functions:**
	- All operations occur in log N time.
	- **==Insert function:==**
	```c++
	//Inserts an element 
	s.insert(ele);
	```
	- **==Emplace function:==**
	```c++
	// Inserts an element similar to insert
	s.emplace(ele);
	```
	- ==**Find function:**==
	```c++
	// Returns a reference to the element
	s.find(ele)
	```
	- If element is not in the set, it returns s.end().
	- ==**Count function:**==
	```c++
	// Returns a count of the element in the set.
	s.count(ele);
	```
	- Returns 0 if there's no occurrence of the element.
	- **==Erase function:==**
	```c++
	// Erases the element passed
	s.erase(ele)

	// Erases the reference passed (usually as an iterator)
	s.erase(itr) 

	// Erase between two references. Upper bound is not included, Lower bound is included as always.
	s.erase(itr1,itr2)
	```
	- **==Lower bound function:==**
	```C++
	// Returns an iterator to the first element greater than or equal to the given element
	s.lower_bound(ele)
	```
	- If all the elements are lesser than the given value, it returns a iterator to the end.(s.end())
	- **==Upper bound function:==**
	```C++
	// Returns a iterator to the first element that is greater than the element in the set
	s.upper_bound(ele)
	```
	- If  no elements are greater than the given value, it returns a iterator to the end.(s.end())
	
	- Also has begin, end, rbegin, rend, size, empty and swap functions.
9. Multiset
	- Similar to a set, but also can also store duplicate elements.
	- The set is sorted, so the duplicate elements are next are to each other
	**Syntax:**
	```c++
	multiset<dtype> name;
	```
	**Functions:**
	- Functions are similar to that of a normal set
	- However a few functions behave differently.
	- **==Insert function:==**
	```c++
	// Now allows multiple occurences of a element to be inserted
	ms.insert(ele);
	ms.insert(ele);  // This is not ignored
	```
	- Erase function:
	```c++
	// Erases all occurences of the element
	ms.erase(ele); 

	// To erase a specific occurence of an element pass the iterator to the erase function
	ms.erase(itr)
	Example:
	//Let ms = {1,1,1}
	ms.erase(ms.find(1))
	// ms = {1,1}
	```
	- Since the elements are sorted, incrementing the iterator will move it to the next occurrence of the element(provided the current iterator is not the last occurrence)
	```c++
	// Erase a collection of elements. As always itr2 is excluded.
	ms.erase(itr1,itr2)
	```
	- **==Count function==**
	```c++
	// Returns the count of all occurences of the element
	ms.count(ele)
	```
10. Unordered Set:
	- Similar to a set, But now stores unsorted values. The order of the values is random
	**Syntax:**
	```c++
	unordered_set<dtype> name;
	```
	**Functions:**
	- Generally, all operations have a O(1) complexity. Worst case is O(N).
	- Similar to that of a set, But the lower bound and upper bound functions do not work.
11. Map:
	- Similar to a dictionary in Python.
	- It has a key that is unique, and has a value corresponding to each key.
	- The key has to be unique, the value need not be unique.
	- The keys are sorted.
	- Most operations are log N time complexity
	**Syntax:**
	```c++
	map<dtype1,dtype2> name;

	//Example
	map<int,pair<int,int>> mpp;  // Mapping a value to a pair of values
	map<pair<int,int>,pair<int,int>> mpp; // Mapping a pair of values to another pair of values.

	// Initalizing Elements
	mpp[key] = value

	// Accessing elements
	// Returns the value pertaining to the key. If key does not exist, it creates a new pair with that key and 0 as its value for int and float data types.
	mpp[key] 
	```
	- The key and value are stored as pair, hence you can access the key using .first and the value using .second over an iterator.
	**Functions:**
	- Emplace function:
	```c++
	// Emplacing a key value collection into the map.
	mpp.emplace({key,value})
	```
	- Insert function:
	```c++
	// Inserting a key value collection into the map.
	mpp.insert({key,value})
	```
	- For both insert and emplace, the key and value should follow their respective data types.
	- **==Find function:==**
	```c++
	// Returns an iterator to the pair which has key equal to the given ele. If key is not found, returns an iterator to .end()
	auto itr = mpp.find(ele)

	// Accessing the pair
	*(itr).first  // key
	*(itr).second // value
	```
	- **==Lower bound function:==**
	```C++
	// Returns an iterator to the first pair having a key greater than or equal to the given element
	mpp.lower_bound(ele)
	```
	- If all the keys are lesser than the given value, it returns a iterator to the end.(s.end())
	
	- **==Upper bound function:==**
	```c++
	// Returns a iterator to the first pair having a key greater than the element in the set
	mpp.upper_bound(ele)
	```
	- If no keys are greater than the given value, it returns a iterator to the end.(s.end())
	- Functions like erase, swap, size, empty are same as previous containers
12. Multimap:
	- Similar to map, but it can also store duplicate keys.
	**Syntax:**
	```c++
	multimap<dtype1,dtype2> name;
	```
	**Functions:** 
	- Same as map, but cannot use 
	```c++
	mpp[key]
	```
13. Unordered Map:
	- Similar to map, but the values are no longer sorted. Sorted in a random order.
	- Works in O(1), worst case is O(N)
	**Syntax:**
	```c++
	unordered_map<dtype1,dtype2> name;
	```
## 3. Functions
- Common Container functions 
	- ==**Push back function:**==
		```c++
		// Push an element to the back of the container
		v.push_back(ele);
		```
	- ==**Emplace back function:**==
		```c++
			v.emplace_back(ele);
		```
		- Emplace back is the same as push back but works faster.
		- However, emplace back does not require the element to be formatted in according to the data type to be pushed back. Ex:
		```c++
		//Example:
		vector<pair<int,int>> vec;
		vec.push_back({1,2});
		vec.emplace_back(1,2);
		```
	- **==Address functions:==**
		```c++
		//Returns the address for the first element
		v.begin();
	
			//Returns the address of the element after the last element
		v.end();
	
			//Returns the address of the element before the first element 
			//Basically reverse the vector and returns the .end() of that new  reversed vector.
		v.rend();
	
		//Returns the address of the last element.
			//Basically reverses the vector and returns the .begin() of that new     reversed vector.
		v.rbegin();
	
		//Returns address of the last element 
		v.back();
			```
	- ==**Erase function:**==
		```c++
		// single element erase
		v.erase(address)
	
				// multiple element erase, address 1 is the element to begin deletion with, and address 2 is the element to end deletion with
		v.erase(address1,address2+1)
		```
				- When you erase an element, the other elements are automatically shifted backwards to adjust the container
	- **==Insert function:==**
		- Very costly function
		```c++
		// single element insert
		v.insert(address, element)
	
		//multiple copies of one element insert
		v.insert(address,number_of_elements,element)
	
		//inserting a container c2 into a container c1
		c1.insert(address,c2.begin(),c2.end())
		c1.insert(address_c1,address1_c2,address2_c2+1)
		```
	- **==Size function:==**
		```c++
		// Returns size of the container
		v.size();
		```
	- **==Pop back function:==**
		```c++
		//Pops the last element of the vector
		v.pop_back();
		```
	- **==Swap function:==**
		```c++
		//Swaps the containers
		v1.swap(v2)
		```
	- **==Clear function:==**
		```c++
		// Erases the entire container
		v.clear();
		```
	- **==Empty function:==**
		```c++
		//Checks if the container is empty
		v.empty();
		```
- Comparator:
	- A Boolean function that allows you compare according to some custom conditions by returning ==**True**== if first argument should come before the second.
	**Syntax:**
	```c++
	bool func(dtype1,dtype1){
		// comparing conditions.
	}
	```
	Example:
	```c++
	/* Given a collection of pairs sort them according to :
	i) Second element in ascending
	ii) If second element equal, sort them according to first element in descending
	*/
	pair<int,int> a[] = {{1,2},{2,1},{4,1}}
	bool pair_comparator(pair<int,int> a,pair<int,int> b){
		if (a.second != b.second)
			return a.second < b.second
		return a.first > b.first
	}
	```
- Pop count:
	- Returns number of 1s in the binary form of the number
	**Syntax:**
	```c++
	// if the data type of num is int
	__builtin_popcount(num)

	// if data type of num is long long
	__builtin_popcountll(num);
	```
## 4. Iterators
- **Syntax:**
	```c++
	dtype::iterator name = (starting element reference)

	Example:
	vector<int>::iterator itr = v.begin()
	```
	- The iterator works on memory addresses like a pointer.
- **Functions:**
	```c++
	//Traversing
	itr++;

	//Accessing the value
	*(itr);
	```
	- The iterator is a basically a pointer and can only be accessed use to the de-reference operator(*).
	- Like a pointer, you can increment or decrement it to move from one memory location to another.
	```c++
	//Example of using an iterator:
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
		//body
	}

	//Instead of writing the entire data type for iterator
	for(auto it = v.begin();it != v.end();it++){
		//body
	}

	//for each loop in c++
	for(auto it: v){
		//body
	}
	```
## 5. Errors
- Iterators cannot be used as data types for maps.
# References

1. [[C++ STL by TUF]]

