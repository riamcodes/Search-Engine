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

| Task        | Planned completion | Actual completion | Time spent in hrs by X | Time spent in hrs by Y |
| ----------- | :-----------------:| :---------------: | :--------------------: | :--------------------: |
| x           | Nov 3              | Nov 6             | 8.5                    | 0                      |

Task:UML, Planned completion: Nov 3, Actual Completion: Nov 2,                                   Time spent in hours by Grace .5, Anekah .5, Ria .5
Task: AVL Tree and Test Cases,  Planned completion: Nov 3, Actual Completion: Nov 3              Time spent in hours by Grace 8 Anekah 1, Ria 0.083
Task: Query Processor and Test Cases, Planned completion: Nov 21, Actual completion: Dec 2nd,    Time spent in hours by Grace 20 Anekah 4, Ria 1
Task: Doc Parser and Test Cases, Planned completion: Nov 21, Actual completion: Dec 2nd,         Time spent in hours by Grace 1, Anekah 8, Ria 20
Task: Index Handler and Test Cases, Planned Completion: Nov 21, Actual completion: Dec 2nd       Time spent in hours by Grace 4, Anekah 20, Ria 4
Task: User Interface, Planned completion: Nov 27, Actual completion: December 2nd                Time spent in hours by Grace 15, Anekah 8, Ria 15
Task: Search Engine, Planned completion: Nov 27, Actual completion: December 3rd                 Time spent in hours by Grace 1, Anekah 5, Ria 5
Task: Hash and Test Cases, Planned completion: Nov 21, Actual completion: Nov 21                 Time spent in hours by Grace 15, Anekah 10, Ria 1
Task: Documentation, Planned completion: Nov 30, Actual completion: December 3rd                 Time spent in hours by Grace 3, Anekah 3, Ria 3
Task: Overall project integration, Planned completion: Nov 30, Actual completion: December 3rd   Time spent in hours by Grace 20, Anekah 20, Ria 20

### High-level Design of Solution

- Add a UML class diagram, etc.
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

### User Documentation
- What are the features of your software?
- Describe how to use the software.
- Some example queries with the results.

### Performance
- Provide statistics (word counts, timing, etc) for indexing all documents (or as many as you can in a reasonable amount of time).

### Bonus Work
Did you attempt any bonuses? If so, please give a brief description of what you did.

   > Yes, we implemented a DSHash class that was used to store the people and organizations.
