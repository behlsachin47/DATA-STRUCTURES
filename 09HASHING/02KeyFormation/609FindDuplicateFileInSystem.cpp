class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        std::unordered_map<std::string, std::vector<string>> mapContentToFiles;
        std::vector<std::vector<std::string>> output;
        for (int i = 0; i < paths.size(); i++) {
            std::stringstream ss (paths[i]);
            std::string directoryPath ;
            //ss >> directoryPath;
            getline(ss, directoryPath, ' ');
            directoryPath += '/';
            
            std::string fileAndContent;
            while (getline(ss, fileAndContent, ' ')) {
                //std::cout << fileAndContent << std::endl;
                //extract file and content
                int index = fileAndContent.find("(");
                std::string file = fileAndContent.substr(0, index);
                std::string content = fileAndContent.substr(index+1);
                
                if (!mapContentToFiles.count(content)) {
                    mapContentToFiles.insert({content, std::vector<std::string> {}});
                }
                mapContentToFiles[content].push_back(directoryPath + file);
                

                 
            }
        }
        
        for (auto iter = mapContentToFiles.begin(); iter != mapContentToFiles.end(); iter++) {
            if (iter->second.size() > 1)
            output.push_back(iter->second);
        }
        
        return output;
        
    }
};