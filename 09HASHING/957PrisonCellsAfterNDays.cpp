class Solution {
public:
    void GiveNextState( const std::vector<int>& currState, std::vector<int>& nextState) {
        int n = currState.size();
        nextState = std::vector<int>(n, 0);
        for (int i = 1; i < n-1; i++)
            if (currState[i-1] == currState[i+1]) nextState[i] = 1;
    } 
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int totalStates = 0;
        if (N == 0)
            return cells;
        int n = cells.size();
        std::vector<int> currState = cells;
        
        if (currState[0] != 0 || currState[n-1] != 0) {
            N--;
            std::vector<int> nextState;
            GiveNextState(currState, nextState);
            currState = nextState;
            cells = currState;
        }
        
        std::unordered_map< int, std::vector<int> > mapDayToStates;
        
        while (1) {
            
            //now go to next state
            mapDayToStates.insert({totalStates++, currState});
            std::vector<int> nextState;
            GiveNextState(currState, nextState);
            
            if (nextState == cells)
                break;
            currState = nextState;
        }
        N = N % totalStates;
        
        //std::cout << totalStates << " " << N << std::endl;
        
        return mapDayToStates[N];
        
    }
};