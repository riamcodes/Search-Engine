# Assignment 4: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Names of all team members:

Grace Schultz, Ria Mukherji, Anekah Kelley

Used free extension: [ ] 24 hrs or [x] 48 hrs

[] Early submission (48 hrs)

[ ] Bonus work. Describe: DSHash

Place [x] for what applies.

## Answers

### Project Management

Complete the tasks and planned completion columns **BEFORE** You start with 
coding!

Weekly milestones/tasks. Set out a plan at the beginning and then record when you got it done.                   

Task:UML, Planned completion: Nov 3, Actual Completion: Nov 2,                                   Time spent in hours by Grace .5, Anekah .5, Ria .5
Task: AVL Tree and Test Cases,  Planned completion: Nov 3, Actual Completion: Nov 3              Time spent in hours by Grace 8 Anekah 1, Ria 0.083
Task: Query Processor and Test Cases, Planned completion: Nov 21, Actual completion: Dec 2nd,    Time spent in hours by Grace 20 Anekah 4, Ria 1
Task: Doc Parser and Test Cases, Planned completion: Nov 21, Actual completion: Dec 2nd,         Time spent in hours by Grace 1, Anekah 8, Ria 20
Task: Index Handler and Test Cases, Planned Completion: Nov 21, Actual completion: Dec 2nd       Time spent in hours by Grace 4, Anekah 20, Ria 4
Task: User Interface, Planned completion: Nov 27, Actual completion: December 2nd                Time spent in hours by Grace 15, Anekah 8, Ria 15
Task: Search Engine, Planned completion: Nov 27, Actual completion: December 3rd                 Time spent in hours by Grace 1, Anekah 5, Ria 5
Task: Hash and Test Cases, Planned completion: Nov 21, Actual completion: Nov 21                 Time spent in hours by Grace 15, Anekah 10, Ria 1
Task: Documentation, Planned completion: Nov 30, Actual completion: December 3rd                 Time spent in hours by Grace 3, Anekah 3, Ria 3
Task: Overall project integration, Planned completion: Nov 30, Actual completion: December 3rd   Time spent in hours by Grace 60, Anekah 60, Ria 60

### High-level Design of Solution

- Add a UML class diagram, etc.

![UML Class Diagram](SearchEngine_UML_page-0001 (1).jpg)
- High-level pseudo code for each component.

Main Pseudo Code:

program main {
    initialize SearchEngine instance named se

    call se's input method with command line arguments (argc, argv)
}

Search Engine Pseudo Code:

class SearchEngine {
    method input(numberOfArguments, argumentsArray) {
        if firstArgument is "index" {
            print "Reading files..."
            traverseSubdirectory with secondArgument
            getIndex from dp and assign to ih
            print "Done!"
            print "Creating persistence, this may take a minute..."
            createPersistence on ih
            print "Persistence has been created!"
        }
        else if firstArgument is "query" {
            print "Reading persistence..."
            readPersistence on ih
            print "Persistence has been read!"
            setIndex of dp and qp with ih
            combineArguments starting from secondArgument into a single string
            parse the combinedArguments using qp
            print "Here are the most relevant documents"
            for each item in qp's printVector {
                print item with count
                print details of item using dp
                increment count
            }
            askUser if they want to see contents of a file
            if user says yes {
                askUser for number of document to display
                getDocumentNumber from user input
                printDocument from dp using qp's printVector at index documentNumber-1
            }
            clear qp's printVector
        }
        else if firstArgument is "ui" {
            readPersistence on ih
            initialQuestion on ui
        }
    }
}

User Interface Pseudo Code:

class UserInterface {
    method initialQuestion() {
        print "Welcome message"
        
        while true {
            displayOptions() // Display options 1 to 6

            getUserInput(answer)

            if answer not in [1, 2, 3, 4, 5, 6] {
                print "Invalid answer message"
                getUserInput(answer)
            }

            if answer is 1 {
                askForDirectoryPath()
                getUserInput(directoryPath)
                startTimer()
                print "Reading files message"
                traverseSubdirectory(directoryPath)
                getIndex from dp and assign to ih
                print "Done message"
                stopTimer()
            }
            else if answer is 2 {
                print "Generating persistence message"
                startTimer()
                getIndex from dp and assign to ih
                createPersistence on ih
                print "Persistence created message"
                stopTimer()
            }
            else if answer is 3 {
                print "Reading persistence message"
                startTimer()
                readPersistence on ih
                setIndex of dp with ih
                print "Persistence read message"
                stopTimer()
            }
            else if answer is 4 {
                setIndexHandler of qp with ih
                askForQuery()
                getUserInput(query)
                startTimer()
                parseQuery(query) // Parse and find relevant documents
                if there are relevant documents {
                    displayDocuments()
                    askUserIfTheyWantToSeeContents()
                    getUserInput(yesOrNo)
                    if yesOrNo is yes {
                        askForDocumentNumber()
                        getUserInput(documentNumber)
                        printDocument()
                    }
                    clear qp's printVector
                    stopTimer()
                }
            }
            else if answer is 5 {
                displayStatistics() // Show runtime and index statistics
            }
            else if answer is 6 {
                print "Thank you message"
                break from loop
            }
        }
    }
}

Index Handler Pseudo Code:

class IndexHandler {
    map words, wordCount, people, orgs
    list docs

    method getWords(word) {
        return entries in words that contain word
    }

    method getWordCount(title) {
        return word count for given title
    }

    method getPeople(person) {
        return entries in people that find person
    }

    method getOrgs(org) {
        return entries in orgs that find org
    }

    method addWordCount(title, count) {
        set wordCount for title to count
    }

    method addWords(word, filepath) {
        insert word and filepath into words
    }

    method addPeople(person, filepath) {
        insert person and filepath into people
    }

    method addOrgs(org, filepath) {
        insert org and filepath into orgs
    }

    method addDocument(filepath) {
        append filepath to docs
    }

    method getDocSize() {
        return size of docs
    }

    method createPersistence() {
        open a file for writing
        if file opening fails, exit with error
        write words, people, orgs, docs, and wordCount to file
        close file
    }

    method readPersistence() {
        open a file for reading
        if file opening fails, exit with error
        while reading file {
            parse the file and populate words, people, orgs, docs, wordCount
        }
        close file
    }

    method returnSize() {
        return size of words
    }
}

Document Parser Pseudo Code:

class DocumentParser {
    IndexHandler ih
    set stopWords

    method setIndex(index) {
        ih = index
    }

    method getIndex() {
        return ih
    }

    method printInfo(jsonContent) {
        open jsonContent file
        if file opening fails, display error and return
        parse jsonContent
        if json parsing fails, display error and return
        extract and print title, publication, and datePublished from json
    }

    method parseDocument(jsonContent) {
        initialize wordCount
        open jsonContent file
        if file opening fails, display error and return
        parse jsonContent
        if json parsing fails, display error and return
        extract and process document information such as title, people, organizations, and text
        for each word in text {
            clean and stem word
            if word is not a stop word {
                add word to IndexHandler
                increment wordCount
            }
        }
        print document ID and word count
    }

    method traverseSubdirectory(directoryPath) {
        open directoryPath
        if directory opening fails, display error and return
        for each subdirectory in directory {
            open subdirectory
            if subdirectory opening fails, display error and continue
            for each file in subdirectory {
                parseDocument with file
            }
            close subdirectory
        }
        close directory
    }

    method printDocument(jsonContent) {
        open jsonContent file
        if file opening fails, display error and return
        parse jsonContent
        if json parsing fails, display error and return
        extract and print title, persons, organizations, and text from json
    }
}

Query Processor Pseudo Code:

class QueryProcessor {
    property IndexHandler indexObject
    list storage
    map relevantDocuments
    map relDocs
    map sendTo
    list printVector

    constructor() {
        // Initializes the QueryProcessor instance
    }

    method setIndexHandler(i) {
        set indexObject to i
    }

    method parsingAnswer(answer) {
        clear storage
        split answer into words and store them in storage
        return the result of dissecting the answer
    }

    method dissectAnswer() {
        for each term in storage {
            if term indicates an organization {
                extract organization name
                get documents related to this organization
                calculate intersection with relevantDocuments
            }
            else if term indicates a person {
                extract person name
                get documents related to this person
                calculate intersection with relevantDocuments
            }
            else if term is a negation {
                extract negated term
                stem the term
                get documents not containing this term
                calculate complement with relevantDocuments
            }
            else {
                stem the term
                if it's the first term {
                    get documents containing this term
                    assign to relevantDocuments
                } else {
                    get documents containing this term
                    calculate intersection with relevantDocuments
                }
            }
        }
        calculate Relevancy for sendTo
        return relDocs
    }

    method intersection(relevantDocuments, docs) {
        create finalVector
        for each document in relevantDocuments {
            if it also exists in docs {
                add to finalVector
            }
        }
        update sendTo
        return finalVector
    }

    method complement(relevantDocuments, docs) {
        create finalVector
        for each document in relevantDocuments {
            if it does not exist in docs {
                add to finalVector
            }
        }
        update sendTo
        return finalVector
    }

    method Relevancy(sendTo) {
        for each document in sendTo {
            calculate term frequency-inverse document frequency (tf-idf)
            assign tf-idf score to the document
        }
        if number of documents in sendTo is less than or equal to 15 {
            add all documents to printVector
        } else {
            add top 15 documents to printVector
        }
        return printVector
    }
}

DSAvl Tree Pseudo Code:

template <typename Comparable, typename Value>
class DSAvlTree {
    private structure DSAvlNode {
        Comparable key
        DSAvlNode left, right
        int height
        map<Value, int> mapVals
        constructor(...)
    }

    DSAvlNode root
    int size

    // Constructor
    DSAvlTree() {
        root = null
        size = 0
    }

    // Copy constructor
    DSAvlTree(rhs) {
        root = clone(rhs.root)
    }

    // Destructor
    ~DSAvlTree() {
        makeEmpty()
    }

    // Assignment operator
    operator=(rhs) {
        makeEmpty()
        root = clone(rhs.root)
        return this
    }

    // Check if a key is in the tree
    contains(x) {
        return contains(x, root)
    }

    // Check if the tree is empty
    isEmpty() {
        return root is null
    }

    // Make the tree empty
    makeEmpty() {
        makeEmpty(root)
        root = null
        size = 0
    }

    // Insert a key-value pair
    insert(x, v) {
        insert(x, v, root)
    }

    insert(x, v, a) {
        insert(x, v, a, root)
    }

    // Remove a key
    remove(x) {
        remove(x, root)
    }

    getSize() {
        return size
    }

    // Print the tree
    printTree(out) {
        printTree(out, root)
    }

    private:

    // Private methods for insertion, removal, balancing, etc.

    insert(x, v, t) {
        // Insert logic with balancing
    }

    insert(x, v, a, t) {
        // Insert logic with specific frequency and balancing
    }

    remove(x, t) {
        // Remove logic with balancing
    }

    deleteLeftMostIn(t) {
        // Delete leftmost node and return its key
    }

    contains(x, t) {
        // Check if a key is in a subtree
    }

    makeEmpty(t) {
        // Empty a subtree
    }

    clone(t) {
        // Clone a subtree
    }

    height(t) {
        // Return the height of a node
    }

    balance(t) {
        // Balance a subtree
    }

    printTree(out, t) {
        // Print a subtree
    }

    rotateWithLeftChild(k2) {
        // Perform a rotation with left child
    }

    rotateWithRightChild(k1) {
        // Perform a rotation with right child
    }

    doubleWithLeftChild(k3) {
        // Perform a double rotation on left child
    }

    doubleWithRightChild(k1) {
        // Perform a double rotation on right child
    }
}

Hash Pseudo Code:

template <typename Comparable, typename Value>
class Hash {
    private struct HashNode {
        Comparable comp
        map<Value, int> maps
        HashNode next
        constructor(...)
    }

    int capacity
    int size
    HashNode array table

    // Constructor
    Hash() {
        createHash()
    }

    // Destructor
    ~Hash() {
        clear()
        delete table array
    }

    // Copy constructor
    Hash(rhs) {
        clone(rhs)
    }

    // Assignment operator
    operator=(rhs) {
        if this is not rhs {
            clear()
            clone(rhs)
        }
        return this
    }

    // Get size of the hash table
    getSize() {
        return size
    }

    // Clear the hash table
    clear() {
        delete each node in table
        create new hash table
        size = 0
    }

    // Create a new hash table
    createHash(x = 100) {
        capacity = x
        size = 0
        table = new HashNode array of size capacity
        initialize each element of table to null
    }

    // Clone another hash table
    clone(copy) {
        createHash with copy's capacity
        copy each node from copy's table to this table
    }

    // Insert a key-value pair
    insert(comp, val) {
        index = hash(comp)
        handle insertion at index
        if table is full, rehash
    }

    insert(comp, val, freq) {
        index = hash(comp)
        handle insertion at index with frequency
        if table is full, rehash
    }

    // Print the hash table
    printHash(out) {
        for each node in table {
            print node's comp and maps
        }
    }

    // Insert with a map
    secondInsert(comp, val) {
        index = hash(comp)
        handle insertion at index with a map
        if table is full, rehash
    }

    // Find a value by key
    find(comp) {
        index = hash(comp)
        search for comp at index
        return found maps or empty map
    }

    private:
    
    // Rehash the table
    rehash() {
        store old table and capacity
        create new hash table with double capacity
        reinsert each node from old table to new table
        delete old table
    }

    // Calculate hash index
    hash(comp) {
        return absolute value of hash function of comp modulo capacity
    }
}

Porter 2 Stemmer Pseudo Code:

class Porter2Stemmer {
    method stem(word) {
        // Process special cases for short words
        // Truncate words longer than 35 characters
        // Handle special cases and apply stemmer algorithm steps 0 to 5
        replace 'Y' with 'y' in word
    }

    method trim(word) {
        // Convert word to lowercase and remove non-alphabetic characters
    }

    private:
    // Internal utility functions used by the stemmer

    method getStartR1(word) {
        // Determine the start index of R1 region in the word
    }

    method getStartR2(word, startR1) {
        // Determine the start index of R2 region in the word
    }

    method firstNonVowelAfterVowel(word, start) {
        // Find the index of the first non-vowel following a vowel
    }

    method changeY(word) {
        // Change 'y' to 'Y' when preceded by a vowel
    }

    method step0(word) {
        // Remove possessive endings
    }

    method step1A(word) {
        // Handle specific suffixes and conditions in step 1A
    }

    method step1B(word, startR1) {
        // Handle specific suffixes and conditions in step 1B
    }

    method step1C(word) {
        // Replace 'y' or 'Y' at the end with 'i' if preceded by a non-vowel
    }

    method step2(word, startR1) {
        // Handle specific suffixes and conditions in step 2
    }

    method step3(word, startR1, startR2) {
        // Handle specific suffixes and conditions in step 3
    }

    method step4(word, startR2) {
        // Handle specific suffixes and conditions in step 4
    }

    method step5(word, startR1, startR2) {
        // Handle specific conditions in step 5
    }

    method isShort(word) {
        // Check if a word is short
    }

    method special(word) {
        // Handle special cases of words
    }

    method isVowelY(ch) {
        // Check if a character is a vowel or 'y'
    }

    method isVowel(ch) {
        // Check if a character is a vowel
    }

    method endsWith(word, str) {
        // Check if a word ends with a specific substring
    }

    method endsInDouble(word) {
        // Check if a word ends in a double consonant
    }

    method replaceIfExists(word, suffix, replacement, start) {
        // Replace a suffix with a replacement if it exists in the word
    }

    method isValidLIEnding(ch) {
        // Check if a character is a valid ending after 'li'
    }

    method containsVowel(word, start, end) {
        // Check if a substring of the word contains a vowel
    }
}

### Used Data Structures
Explanation of what data structures are used where. For each, state
    - time and space complexity (Big-Oh),
    - why it is the appropriate data structure and what other data structure could have been used.

1. AVL Trees

Used In: Indexing words, people, and organizations

Time Complexity:

Insertion: O(logn)

Deletion: O(logn)

Search: O(logn)

Space Complexity: O(n)

Appropriateness:

AVL trees are self-balancing binary search trees, ensuring that the tree remains balanced with insertions and deletions, providing consistent
time complexity for basic operations. They are helpful for applications where data is frequently inserted and removed.

Alternative Data Structure:

Red-Black Trees which have a similar performance in terms of time complexity, but easier to implement. However, they might be less balanced compared to AVL trees, leading to slightly longer search times in the worst case.

2. Hash Tables

Used In: Storing mappings from a key to a set of documents.

Time Complexity:

Insertion: Average O(1), Worst O(n)

Search: Average O(1), Worst O(1)

Deletion: Average O(1), Worst O(n)

Space Complexity: O(n)

Appropriateness:

Hash tables offer very fast average-time complexity for insertions, deletions, and searches, making them ideal for indexing where quick lookup is necessary.
They efficiently handle large datasets with an average-case constant time complexity.

3. Vectors

Used In: Storing a list of documents, storing query results, etc.

Time Complexity:

Insertion at the end: O(1)

Access by Index: O(1) 

Insertion/Deletion at a given position: O(n)

Space Complexity: O(n)

Appropriateness:

Vectors are helpful in situations where random access is important.

Alternative Data Structure:

Deques which are similar to vectors but are efficient at inserting or deleting at both ends.

4. Maps

Used In: Associating keys with values.

Time Complexity:

Insertion, Deletion, Search: O(logn)

Space Complexity: O(n)

Appropriateness:

Maps provide a sorted key-value pair mapping, which is helpful for ordered data manipulation.

Alternative Data Structure:

Unordered Maps which provide average constant-time complexity for the same operations but don't maintain order.

### User Documentation
- What are the features of your software?

UserInterface:

Provides a user interface for interacting with the search engine.
Offers options like creating an index, writing/reading an index to/from a file, entering a query, viewing statistics, and quitting.
Handles user input and directs the flow of operations based on that input.

SearchEngine:

Manages the main functionality of the search engine.
Includes methods for processing input, which could be commands for indexing or querying.
Utilizes DocumentParser and IndexHandler for handling document parsing and indexing.

DocumentParser:

Responsible for parsing documents in JSON format.
Handles operations like reading documents from a directory, parsing individual documents, and extracting relevant information (like title, people, organizations, and text).
Also contains functionality to process and stem words, excluding stopwords.

DSAvlTree:

A template class representing an AVL Tree.
Contains methods for inserting, removing, balancing, and searching nodes.
Utilized for efficient storage and retrieval of data.

Hash:

A template class for a hash table.
Supports operations like insertion, searching, rehashing, and clearing.
Efficiently stores and retrieves people and organizations.

IndexHandler:

Manages the indexing process.
Contains methods for adding words, people, organizations, and documents to the index.
Handles creation and reading of persistence.

Porter2Stemmer:

Implements the Porter2 (or "Snowball") stemming algorithm.
Used for reducing words to their base or root form.

QueryProcessor:

Handles the processing of search queries.
Parses user input to identify terms related to organizations, people, and general words.
Contains methods for intersecting and complementing document sets based on query terms.

- Describe how to use the software.

User Guide for Search Engine Application

Introduction:

Welcome to our search engine application designed to efficiently index, manage, and query a vast collection of documents. This guide provides step-by-step instructions on how to interact with the application and utilize its features effectively.

Getting Started

Launching the Application:

To start, run the main executable of the search engine.
Upon launch, you will be greeted with a welcome message and a list of options.

Main Menu Options:

The main menu shows you the following choices:
- Create an index from a directory with documents
- Write an index to a file
- Read an index from a file
- Enter a query
- See statistics
- Quit

Creating an Index:

Choose option 1 to index documents from a specified directory.
Enter the path to the directory containing the documents when prompted.
The system will process the documents and create an index, notifying you upon completion.

Writing an Index to a File:

Select option 2 to save the created index to a file.
The application will automatically generate and save the index, ensuring data persistence.

Reading an Index from a File:

Choose option 3 to load a previously saved index.
This option allows you to efficiently resume work with an existing dataset.

Querying the Index:

Select option 4 to enter a search query.
Type your query as instructed. You can search for specific words, people, organizations, or a combination of these.
The system will return the most relevant documents based on your query.

Viewing Statistics:

Choose option 5 to view statistics like total runtime, the number of indexed articles, and the number of unique words indexed.

Exiting the Application:

Select option 6 to safely exit the application.

- Some example queries with the results.

./supersearch query finance ORG:reuters (Select option 4 in the user interface and type "finance ORG:reuters")

Reading persistence...
Persistence has been read!
Here are the most relevant documents
1. Title: BRIEF-Magma Fincorp Approves Amalgamation Of Magma ITL Finance With Co, Publication: reuters.com, Date Published: 2018-01-16

2. Title: Petrobras not eyeing shareholder settlements elsewhere unless forced by law, Publication: reuters.com, Date Published: 2018-01-17

3. Title: Eurogroup's Centeno urges completion of bank union, backs euro zone budget, Publication: reuters.com, Date Published: 2018-01-17

4. Title: Carillion collapse regrettable, but government cannot bail it out - PM May's spokesman, Publication: reuters.com, Date Published: 2018-01-15

5. Title: BRIEF-Baoding Tianwei Baobian Electric Revises Share Private Placement, Plans To Obtain Financing, Publication: reuters.com, Date Published: 2018-01-12

6. Title: BRIEF-Owkin Closes $11 Million Series A Financing Round, Publication: reuters.com, Date Published: 2018-01-16

7. Title: Key Senate committee advances Azar nomination for HHS secretary, Publication: reuters.com, Date Published: 2018-01-17

8. Title: Germany demands clarity on risk reduction for banking union, Publication: reuters.com, Date Published: 2018-01-17

9. Title: Bitcoin slides 14 percent on crackdown fears, hits four-week low, Publication: reuters.com, Date Published: 2018-01-16

10. Title: UPDATE 1-French families plan to sue retailers over baby milk recall -group, Publication: reuters.com, Date Published: 2018-01-15

11. Title: Signs of division in Cambodia's opposition over new group, Publication: reuters.com, Date Published: 2018-01-15

12. Title: Don't see problem with dollar around 110.80 yen: Japan finance minister, Publication: reuters.com, Date Published: 2018-01-16

13. Title: Urals diffs inch up in NWE, Publication: reuters.com, Date Published: 2018-01-16

14. Title: Egypt's budget deficit in first half FY 2017-18 down to 4.4 pct, Publication: reuters.com, Date Published: 2018-01-14

15. Title: Economists call for overhaul of euro zone, creation of joint 'safe assets', Publication: reuters.com, Date Published: 2018-01-17


./supersearch query happy (Select option 4 in the user interface and type "happy")

Reading persistence...
Persistence has been read!
Here are the most relevant documents
1. Title: Shorts on top as January CBOE bitcoin futures near settlement, Publication: reuters.com, Date Published: 2018-01-17

2. Title: Physician burnout takes a toll on U.S. patients, Publication: reuters.com, Date Published: 2018-01-17

3. Title: Tennis-Coco goes bananas as Americans slip up at Australian Open, Publication: reuters.com, Date Published: 2018-01-15

4. Title: Saudi Arabia begins screening films after decades-long ban lifted, Publication: reuters.com, Date Published: 2018-01-15

5. Title: Highlights: Australian Open day two, Publication: reuters.com, Date Published: 2018-01-16

6. Title: Data Sheet—Facebook and Twitter Will Still Work With Disney, Until They Can't - Fortune, Publication: fortune.com, Date Published: 2018-01-17

7. Title: Nadal charges into second round at Australian Open, Publication: reuters.com, Date Published: 2018-01-15

8. Title: CEO Elle Kaplan: EQ can make you successful, according to science, Publication: cnbc.com, Date Published: 2018-01-16

9. Title: WatchGuard Technologies Acquires Percipient Networks and Adds Security at the DNS Layer to Company's SMB Security Platform, Publication: cnbc.com, Date Published: 2018-01-17

10. Title: Resilient Svindal back on form and gunning for gold, Publication: reuters.com, Date Published: 2018-01-12

11. Title: Horrible carriage, unwieldy crowns: Queen Elizabeth's candid views of coronation and royal jewels, Publication: reuters.com, Date Published: 2018-01-12

12. Title: Tennis - Tsonga tames Shapovalov in five-set classic, Publication: reuters.com, Date Published: 2018-01-17

13. Title: Optimism in Iraq fuels revived interest in vintage cars, Publication: cnbc.com, Date Published: 2018-01-17

14. Title: One surprising reason for more positive pregnancy tests this month, Publication: reuters.com, Date Published: 2018-01-19

15. Title: The top 25 US companies to work for if you want to be happier, Publication: cnbc.com, Date Published: 2018-01-18


./supersearch query ocean (Select option 4 in the user interface and type "ocean")

Reading persistence...
Persistence has been read!
Here are the most relevant documents
1. Title: EU targets recycling as China bans plastic waste imports, Publication: reuters.com, Date Published: 2018-01-16

2. Title: CSX Corporation Announces Fourth Quarter and Full-Year 2017 Earnings, Publication: cnbc.com, Date Published: 2018-01-17

3. Title: Black smoke billows from tanker sinking site as worry grows over sea damage, Publication: reuters.com, Date Published: 2018-01-15

4. Title: Marriott Dragged into Fight Over Trump Panama Hotel | Fortune, Publication: fortune.com, Date Published: 2018-01-04

5. Title: Southeast Asian plastic recyclers hope to clean up after China ban, Publication: reuters.com, Date Published: 2018-01-16

6. Title: Qantas named most polluting airline across Pacific Ocean, Publication: cnbc.com, Date Published: 2018-01-17

7. Title: The Last Place on Earth Where Everyone Still Loves Kmart, Publication: wsj.com, Date Published: 2018-01-16

8. Title: Highlights: Australian Open day two, Publication: reuters.com, Date Published: 2018-01-16

9. Title: Hawaii officials stir panic with ‘false alarm’ about missile threat - MarketWatch, Publication: wsj.com, Date Published: 2018-01-13

10. Title: Materials drag Australian shares to 4-week low; NZ climbs, Publication: reuters.com, Date Published: 2018-01-17

11. Title: EU: Plastics Packaging to be Reusable or Recyclable by 2030 | Fortune, Publication: fortune.com, Date Published: 2018-01-17

12. Title: Iranian oil tanker wreck produces 2 slicks in East China Sea - China, Publication: reuters.com, Date Published: 2018-01-17

13. Title: What The China Oil Spill Means For Your Next Seafood Dinner | Fortune, Publication: fortune.com, Date Published: 2018-01-18

14. Title: Trump says border wall stance has not 'evolved,' Mexico will pay, Publication: reuters.com, Date Published: 2018-01-18

15. Title: Private Ocean Announces Acquisition of Lakeview Financial Group, Publication: cnbc.com, Date Published: 2018-01-17


./supersearch query facebook PERSON:mark (Select option 4 in the user interface and type "facebook ORG:mark")

Reading persistence...
Persistence has been read!
Here are the most relevant documents
1. Title: Mark Zuckerberg Says Facebook to Become 'More Meaningful' | Fortune, Publication: fortune.com, Date Published: 2018-01-13

2. Title: 'Shark Tank': The Long Hairs land $100,000 investment from Mark Cuban, Publication: cnbc.com, Date Published: 2018-01-15

3. Title: emphasize, Publication: cnbc.com, Date Published: 2018-01-20

4. Title: UPDATE 1- prioritize sources, Publication: cnbc.com, Date Published: 2018-01-19

5. Title: The Trump Paradox, Publication: wsj.com, Date Published: 2018-01-18

6. Title: Facebook CEO Mark Zuckerberg's Clueless Local News Plans | Fortune, Publication: fortune.com, Date Published: 2018-01-30

7. Title: Facebook to promote local news in latest update, Publication: cnbc.com, Date Published: 2018-01-29

8. Title: Barbara Corcoran landed her spot on ‘Shark Tank’ with an email, Publication: cnbc.com, Date Published: 2018-01-11

9. Title: Q&A: What Facebook's shift could mean to users, businesses, Publication: cnbc.com, Date Published: 2018-01-12

10. Title: Zuckerberg changes Facebook's focus to be more 'meaningful', Publication: cnbc.com, Date Published: 2018-01-12

11. Title: Smartsheet acquires Converse.AI to accelerate natural language user experiences and conversational workflow automation, Publication: cnbc.com, Date Published: 2018-01-16

12. Title: Facebook Leads Denmark to Charge 1,000 in Underage Sex Case | Fortune, Publication: fortune.com, Date Published: 2018-01-15

13. Title: Facebook Feed Changes Cost Mark Zuckerberg Billions | Fortune, Publication: fortune.com, Date Published: 2018-01-15

14. Title: ANGUS Chemical Company Names Dave Neuberger as Chief Executive Officer, Publication: cnbc.com, Date Published: 2018-01-16

15. Title: BRIEF-Facebook CEO Mark Zuckerberg says optimistic DACA "will get solved"‍​, Publication: reuters.com, Date Published: 2018-01-17


./supersearch query facebook PERSON:mark PERSON:zuckerberg (Select option 4 in the user interface and type "facebook PERSON:mark PERSON:zuckerberg)

1. Title: Mark Zuckerberg Says Facebook to Become 'More Meaningful' | Fortune, Publication: fortune.com, Date Published: 2018-01-13

2. Title: emphasize, Publication: cnbc.com, Date Published: 2018-01-20

3. Title: UPDATE 1- prioritize sources, Publication: cnbc.com, Date Published: 2018-01-19

4. Title: The Trump Paradox, Publication: wsj.com, Date Published: 2018-01-18

5. Title: Facebook CEO Mark Zuckerberg's Clueless Local News Plans | Fortune, Publication: fortune.com, Date Published: 2018-01-30

6. Title: Facebook to promote local news in latest update, Publication: cnbc.com, Date Published: 2018-01-29

7. Title: Q&A: What Facebook's shift could mean to users, businesses, Publication: cnbc.com, Date Published: 2018-01-12

8. Title: Zuckerberg changes Facebook's focus to be more 'meaningful', Publication: cnbc.com, Date Published: 2018-01-12

9. Title: Facebook Leads Denmark to Charge 1,000 in Underage Sex Case | Fortune, Publication: fortune.com, Date Published: 2018-01-15

10. Title: Facebook Feed Changes Cost Mark Zuckerberg Billions | Fortune, Publication: fortune.com, Date Published: 2018-01-15

11. Title: BRIEF-Facebook CEO Mark Zuckerberg says optimistic DACA "will get solved"‍​, Publication: reuters.com, Date Published: 2018-01-17

12. Title: Facebook shares slip after News Feed overhaul, Publication: reuters.com, Date Published: 2018-01-13

13. Title: UPDATE 2-Facebook changes News Feed, investors click on 'sad', Publication: cnbc.com, Date Published: 2018-01-12

14. Title: How Mark Zuckerberg came up with the idea for Facebook, Publication: cnbc.com, Date Published: 2018-01-18

15. Title: Zuckerberg says fixing Facebook is his personal challenge for 2018, Publication: cnbc.com, Date Published: 2018-01-04


./supersearch query german ORG:bdi (Select option 4 in the user interface and type "german ORG:bdi")

Reading persistence...
Persistence has been read!
Here are the most relevant documents
1. Title: Germany faces huge bill to meet EU climate goals: BDI study, Publication: reuters.com, Date Published: 2018-01-17

2. Title: German industry group says Iran protests not hurting economic ties, Publication: reuters.com, Date Published: 2018-01-04

### Performance
- Provide statistics (word counts, timing, etc) for indexing all documents (or as many as you can in a reasonable amount of time).

It takes one hour and 21 minutes to index 300,000 documents.
It takes 17.1602 seconds to index 6,000 documents.

### Bonus Work
Did you attempt any bonuses? If so, please give a brief description of what you did.

   > Yes, we implemented a DSHash class that was used to store the people and organizations.
