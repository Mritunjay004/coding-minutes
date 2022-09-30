#include <bits/stdc++.h>
using namespace std;

class Car
{
public:
    string id;
    int x, y;
    Car(string id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist() const
    {
        return (x * x) + (y * y); //* for eucludian dist, there is also a sq root but we can find using it only so
    }
};

class compare
{
public:
    bool operator()(Car A, Car B)
    {
        return A.dist() < B.dist(); // * this is for max heap, as max heap is default
    }
};

void printNearestCars(vector<Car> cars, int k)
{
    priority_queue<Car, vector<Car>, compare> max_heap(cars.begin(), cars.begin() + k);

    //*remaining cars
    for (int i = k; i < cars.size(); i++)
    {
        Car car = cars[i];
        if (car.dist() < max_heap.top().dist())
        //* if smaller than largest add it and remove the largest
        {
            max_heap.pop();
            max_heap.push(car);
        }
    }

    //* heap will contain acc to max heap so doing below steps to get in from lowest
    vector<Car> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(max_heap.top());
        max_heap.pop();
    }

    reverse(res.begin(), res.end());

    for (auto it : res)
        cout << it.id << endl;

    return;
}

int main()
{
    int n, k;
    cin >> n >> k;

    string id;
    int x, y;

    vector<Car> cars;

    for (int i = 0; i < n; i++)
    {
        cin >> id >> x >> y;
        Car car(id, x, y);
        cars.push_back(car);
    }

    printNearestCars(cars, k);
    return 0;
}
