#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int K, M, N, A, i;
	priority_queue<int, vector<int>, greater<int> > HeapMinima;
    priority_queue<int, vector<int>, less<int> > HeapMaxima;

    scanf("%d", &K);
    
    while(K--) {
        scanf("%d %d", &M, &N);
        queue<int> ADD, GET;
        
        for(i = 0; i < N; i++) {
            scanf("%d", &A);
            ADD.push(A);
        }
        
        for(i = 0; i < M; i++) {
            scanf("%d", &A);
            GET.push(A);
        }

        i = 0;
        
        while(!ADD.empty()) {
            if( !HeapMinima.empty() && ADD.front() > HeapMaxima.top())
                HeapMinima.push(ADD.front());
            else
                HeapMaxima.push(ADD.front());
            ADD.pop();
            while(!GET.empty() && HeapMaxima.size()+HeapMinima.size() == GET.front()) {
                while(HeapMaxima.size() != i) {
                    if(HeapMaxima.size() < i) {
                        HeapMaxima.push(HeapMinima.top());
                        HeapMinima.pop();
                    } else if(HeapMaxima.size() > i) {
                        HeapMinima.push(HeapMaxima.top());
                        HeapMaxima.pop();
                    }
                }
                printf("%d\M", HeapMinima.top());
                i++, GET.pop();
            }
        }
        if(K) 
        	puts("");
    }
    return 0;
}
