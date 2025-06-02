#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*============================
      Notification & Decorators
=============================*/
// Abstract class
class INotification
{
public:
    virtual string getContent() = 0;
    virtual ~INotification() {}
};

// Concrete Notification: simple text notification.
class SimpleNotification : public INotification
{
private:
    string text;

public:
    // constructor
    SimpleNotification(const string &msg)
    {
        this->text = msg;
    }
    string getContent() override
    {
        return text;
    }
};

// Abstract Decorator: wraps a Notification object.
class INotificationDecorator : public INotification
{
protected:
    INotification *notification;

public:
    // constructor
    INotificationDecorator(INotification *notification)
    {
        this->notification = notification;
    }
};

// Decorator to add a timestamp to the content.
class TimestampDecorator : public INotificationDecorator
{
public:
    // constructor
    TimestampDecorator(INotification *notification) : INotificationDecorator(notification) {}
    string getContent() override
    {
        return "[2025-04-13 14:22:00] " + notification->getContent();
    }
};

// Decorator to append a signature to the content.
class SignatureDecorator : public INotificationDecorator
{
private:
    string signature;

public:
    // constructor
    SignatureDecorator(INotification *notification, const string &sig) : INotificationDecorator(notification)
    {
        this->signature = sig;
    }

    string getContent() override
    {
        return notification->getContent() + signature + "\n";
    }
};

/*============================
  Observer Pattern Components
=============================*/
// Observer interface: each observer gets an update with a Notification pointer.

// Observer
class IObserver
{
public:
    virtual void update() = 0;
    virtual ~IObserver() {}
};
// Observable
class IObservable
{
public:
    virtual void addObserver(IObserver *observer) = 0;
    virtual void removeObserver(IObserver *observer) = 0;
    virtual void notifyObserver() = 0;
};

// concrete observable
class NotificationObservable : public IObservable
{
private:
    vector<IObserver *> observer;
    INotification *currNotification;

public:
    // constructor
    NotificationObservable()
    {
        currNotification = nullptr;
    }
    void addObserver(IObserver *obs) override
    {
        observer.push_back(obs);
    }

    void removeObserver(IObserver *obs) override
    {
        observer.erase(remove(observer.begin(), observer.end(), obs), observer.end());
    }

    void notifyObserver() override
    {
        for (auto itr : observer)
        {
            itr->update();
        }
    }

    void setNotification(INotification *notification)
    {
        if (currNotification != nullptr)
        {
            delete currNotification;
        }
        currNotification = notification;
        notifyObserver();
    }

    INotification *getNotification()
    {
        return currNotification;
    }

    string getNotificationContent()
    {
        return currNotification->getContent();
    }

    ~NotificationObservable()
    {
        if (currNotification != nullptr)
        {
            delete currNotification;
        }
    }
};

// Concrete Observer 1
class Logger : public IObserver
{
private:
    NotificationObservable *notificationObservable;

public:
    Logger(NotificationObservable *observable)
    {
        this->notificationObservable = observable;
    }
    void update() override
    {
        cout << "Logging New Notification : \n"
             << notificationObservable->getNotificationContent();
    }
};

/*============================
  Strategy Pattern Components (Concrete Observer 2)
=============================*/
// Abstract class for different Notification Strategies.
class INotificationStrategy
{
public:
    virtual void sendNotification(string content) = 0;
};

// Concrete Strategy
class EmailStrategy : public INotificationStrategy
{
private:
    string emailId;

public:
    // constructor
    EmailStrategy(string emailId)
    {
        this->emailId = emailId;
    }
    void sendNotification(string content)
    {
        // Simulate the process of sending an email notification,
        // representing the dispatch of messages to users via email.​
        cout << "Sending email Notification to: " << emailId << "\n"
             << content;
    }
};

class SMSStrategy : public INotificationStrategy
{
private:
    string mobileNo;

public:
    // constructor
    SMSStrategy(string mobileNo)
    {
        this->mobileNo = mobileNo;
    }

    void sendNotification(string content) override
    {
        // Simulate the process of sending an SMS notification,
        // representing the dispatch of messages to users via SMS.​
        cout << "Sending SMS Notification to: " << mobileNo << "\n"
             << content;
    }
};

class PopUpStrategy : public INotificationStrategy
{
public:
    void sendNotification(string content) override
    {
        // Simulate the process of sending popup notification.
        cout << "Sending Popup Notification: \n"
             << content;
    }
};

// Observer 2
class NotificationEngine : public IObserver
{
private:
    NotificationObservable *notificationObservable;
    vector<INotificationStrategy *> notificationStrategy;

public:
    //  constructor
    NotificationEngine(NotificationObservable *observable)
    {
        this->notificationObservable = observable;
    }
    void addNotificationStrategy(INotificationStrategy *ns)
    {
        notificationStrategy.push_back(ns);
    }
    void update() override
    {
        for (auto itr : notificationStrategy)
        {
            itr->sendNotification(notificationObservable->getNotificationContent());
        }
    }
};

/*============================
       NotificationService
=============================*/
// <<Sigleton>> class
class NotificationService
{
private:
    static NotificationService *instance;
    NotificationObservable *observable;
    vector<INotification *> notifications;

    // private constructor
    NotificationService()
    {
        observable = new NotificationObservable();
    }

public:
    static NotificationService *getInstance()
    {
        return instance;
    }

    // Expose the observable so observers can attach.
    NotificationObservable *getObservable()
    {
        return observable;
    }
    // Creates a new Notification and notifies observers.
    void sendNotification(INotification *notification)
    {
        this->notifications.push_back(notification); // history
        observable->setNotification(notification);
    }
    ~NotificationService()
    {
        delete observable;
    }
};

NotificationService *NotificationService::instance = new NotificationService();

// main method
int main()
{
    // Create NotificationService.
    NotificationService *notificationService = NotificationService::getInstance();

    // get Observable
    NotificationObservable *notificationObservable = notificationService->getObservable();

    // Create Logger Observer
    Logger *logger = new Logger(notificationObservable);

    // Create NotificationEngine observers.
    NotificationEngine *notificationEngine = new NotificationEngine(notificationObservable);
    notificationEngine->addNotificationStrategy(new EmailStrategy("santu700141@gmail.com"));
    notificationEngine->addNotificationStrategy(new SMSStrategy("9832487454"));
    notificationEngine->addNotificationStrategy(new PopUpStrategy());

    // Attach these observers.
    notificationObservable->addObserver(logger);
    notificationObservable->addObserver(notificationEngine);

    // Create a notification with decorators.
    INotification *notification=new SimpleNotification("Your order has been shipped!");
    notification=new TimestampDecorator(notification);
    notification=new SignatureDecorator(notification,"Customer Care");

    notificationService->sendNotification(notification);
    return 0;
}