string Solution::simplifyPath(string A) {
    std::string directory;
    std::stack<std::string> pathStack;
    std::stack<std::string> tempStack;
    std::stringstream inputStream(A);
    while (std::getline(inputStream, directory, '/')) {
        //std::cout << directory << std::endl;
        if (directory == "" || directory == ".")
            continue;
        else if (directory == "..") {
            if (pathStack.empty() == false) {
                pathStack.pop();
            }
        } else {
            pathStack.push(directory);
        }
    }
    
    std::string output = "/";
    while (pathStack.size()) {
        tempStack.push(pathStack.top());
        pathStack.pop();
    }
    
    while (tempStack.size()) {
        output += tempStack.top() ;
        tempStack.pop();
        if (tempStack.size())
            output += "/";
    }
    
    return output;
}
