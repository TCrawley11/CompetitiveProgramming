#include <iostream>
#include <queue>
#include <string>

struct query {
    std::string name;
    int time;

    query(std::string name, int time): name(name), time(time) {}

    std::string get_name() const {
        return this->name;
    }

    int get_time() const {
        return this->time;
    }

    void set_time(int time) {
        this-> time = time;
    }
};

void parse_queue(std::queue<query>& query_queue, int quantum, int& tracker, std::queue<query>& finished_queries) {
    while(!query_queue.empty()){
        query curr = query_queue.front();
        query_queue.pop();

        int execution_time = std::min(curr.get_time(), quantum);

        if (execution_time == curr.get_time()) {
            curr.set_time(execution_time + tracker);
            finished_queries.push(curr);
            tracker += execution_time;
        } else {
            curr.set_time(curr.get_time() - execution_time);
            query_queue.push(curr);
            tracker += execution_time;
        }
    }
}

void print_queue(std::queue<query>& query_queue){
    auto temp = query_queue;
    while(!temp.empty()){
        std::cout << temp.front().name << ' ' << temp.front().time << std::endl;
        temp.pop();
    }
}

int main() {
    // keep track of time elapsed to define length of time for queries
    int tracker = 0;;
    std::queue<query> finished_queries;

    int n, q;
    std::cin >> n >> q;
    
    std::queue<query> query_queue;

    for (int i = 0; i < n; i++) {
        std::string name;
        int time;
        std::cin >> name >> time;
        query curr = query(name, time);
        query_queue.push(query(name, time));
    }

    parse_queue(query_queue, q, tracker, finished_queries);
    print_queue(finished_queries);

    return 0;
}