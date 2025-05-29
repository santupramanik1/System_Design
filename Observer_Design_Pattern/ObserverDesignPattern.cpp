#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Abstract Observer interface: Subscriber interface
class ISubscriber
{
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {} // virtual destructor for interface
};

// Abstract Observable interface: a YouTube channel interface
class IChannel
{
public:
    virtual void subscribe(ISubscriber *subscriber) = 0;
    virtual void unSubscribe(ISubscriber *subscriber) = 0;
    virtual void notifySubscriber() = 0;
    virtual ~IChannel() {} // virtual destructor for interface
};



// Concrete Subject: a YouTube channel that observers can subscribe to
class Channel : public IChannel
{
private:
    vector<ISubscriber *> subscribers;
    string channelName;
    string latestVideo;

public:
    // constructor
    Channel(const string &name)
    {
        this->channelName = name;
    }
    // subscribe() add the subsriber into the list
    void subscribe(ISubscriber *subscriber) override
    {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end())
        {
            subscribers.push_back(subscriber);
        }
    }

    // unSubscribe() remove the subscriber from the List when they subscribe the channel
    void unSubscribe(ISubscriber *subscriber) override
    {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end())
        {
            subscribers.erase(it);
        }
    }

    // notify the subsriber when new video is uploaded
    void notifySubscriber() override
    {
        for (auto it : subscribers)
        {
            it->update();
        }
    }

    // upload new video
    void uploadVideo(const string &title)
    {
        latestVideo = title;
        cout << "\n[" << channelName << " uploaded \"" << title << "\"]\n";
        notifySubscriber();
    }

    // Read video data
    string getVideoData()
    {
        return "\nCheckout our new Video : " + latestVideo + "\n";
    }
};

// Concrete Observer: represents a subscriber to the channel
class Subscriber : public ISubscriber
{
private:
    Channel *channel;
    string subscriberName;

public:
    // constructor
    Subscriber(const string &name, Channel *channel)
    {
        this->subscriberName = name;
        this->channel = channel;
    }
    void update() override
    {
        cout << "Hey " << subscriberName << "," << channel->getVideoData();
    }
};

// main method
int main()
{
    Channel *channel = new Channel("CoderArmy");

    Subscriber *subs1 = new Subscriber("Santu", channel);
    Subscriber *subs2 = new Subscriber("Saikat", channel);

    // santu and saikat subscribe to CoderArmy
    channel->subscribe(subs1);
    channel->subscribe(subs2);

    // Upload a video: both  santu and saikat are notified
    channel->uploadVideo("Observer Pattern Tutorial");

    // saikat unsubscribes; Tarun remains subscribed
    channel->unSubscribe(subs2);

    // Upload another video: only santu is notified
    channel->uploadVideo("Decorator Pattern Tutorial");
    return 0;
}