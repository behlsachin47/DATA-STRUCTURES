void generate(ll n)
{
    std::queue<string> q;
    q.push("1");
    ll count = 1;
    while (q.size()) {
        string top = q.front();
        std::cout << top << " ";
        q.pop();
        
        if (count < n) {
            q.push(top + '0');
            count++;
        }
        if (count < n) {
            q.push(top + '1');
            count++;
        }
    }
	// Your code here
}