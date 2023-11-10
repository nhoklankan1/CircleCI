//#include <iostream>
//#include <vector>
//
//// Subject (Người quản lý) - Quản lý thông tin về thời tiết và thông báo sự thay đổi
//class WeatherStation
//{
//public:
//    void addObserver(class WeatherObserver *observer);
//    void removeObserver(class WeatherObserver *observer);
//    void setTemperature(float temperature);
//    void notifyObservers();
//
//private:
//    float temperature;
//    std::vector<WeatherObserver *> observers;
//};
//
//// Observer (Người quan tâm) - Định nghĩa giao diện cho các đối tượng quan tâm
//class WeatherObserver
//{
//public:
//    virtual void update(float temperature) = 0;
//};
//
//// Concrete Observer (Người quan tâm cụ thể) - Hiển thị thông báo khi thời tiết thay đổi
//class Display : public WeatherObserver
//{
//public:
//    Display(const std::string &name) : name(name) {}
//    void update(float temperature) override
//    {
//        std::cout << "Display " << name << " received a notification: Temperature is " << temperature << " degrees Celsius." << std::endl;
//    }
//
//private:
//    std::string name;
//};
//
//void WeatherStation::addObserver(WeatherObserver *observer)
//{
//    observers.push_back(observer);
//}
//
//void WeatherStation::removeObserver(WeatherObserver *observer)
//{
//    // Remove the observer from the list
//    auto it = std::find(observers.begin(), observers.end(), observer);
//    if (it != observers.end())
//    {
//        observers.erase(it);
//    }
//}
//
//void WeatherStation::setTemperature(float temperature)
//{
//    this->temperature = temperature;
//    notifyObservers();
//}
//
//void WeatherStation::notifyObservers()
//{
//    for (WeatherObserver *observer : observers)
//    {
//        observer->update(temperature);
//    }
//}
//
//int main()
//{
//    // Tạo đối tượng WeatherStation (người quản lý)
//    WeatherStation weatherStation;
//
//    // Tạo các đối tượng Display (người quan tâm)
//    Display display1("Display 1");
//    Display display2("Display 2");
//
//    // Đăng ký các đối tượng Display cho thông báo
//    weatherStation.addObserver(&display1);
//    weatherStation.addObserver(&display2);
//
//    // Mô phỏng việc thay đổi nhiệt độ và thông báo cho các người quan tâm
//    weatherStation.setTemperature(25.0);
//    weatherStation.setTemperature(30.0);
//
//    // Gỡ đăng ký một đối tượng Display và thông báo lại
//    weatherStation.removeObserver(&display1);
//    weatherStation.setTemperature(35.0);
//
//    return 0;
//}
