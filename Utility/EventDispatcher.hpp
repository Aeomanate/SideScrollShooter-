//
// Created by User on 7/23/2022.
//

#ifndef TESTGAME_EVENTDISPATCHER_HPP
#define TESTGAME_EVENTDISPATCHER_HPP


#include <functional>
#include <set>

template <class... Params>
class EventDispatcher {
  public:
    using EventHandlerSingature = std::function<void(void*, Params...)>;
    
    void EmitEvent(Params&&... params) {
        for(Subscriber const& subscriber: subscribers) {
            subscriber.eventHandler(subscriber.ptr, std::forward<Params>(params)...);
        }
    }
    
    template <class SubscriberT, class MemberF = void(SubscriberT::*)(Params...)>
    void Subscribe(SubscriberT* subscriber, MemberF memberFunc ) {
        Subscriber new_subscriber { subscriber, [memberFunc] (void* subscriber, Params... params) {
            std::string t = typeid(SubscriberT).name();
            (static_cast<SubscriberT*>(subscriber)->*memberFunc)(std::forward<Params>(params)...);
        }};
        subscribers.insert(new_subscriber);
    }
    
    void Subscribe(void* subscriber, EventHandlerSingature handler) {
        subscribers.insert(              subscriber,                    handler);
    }
    
    void Unsubscribe(void* subscriber) {
        subscribers.erase(subscriber);
    }
  
    size_t GetSubscribersCount() const {
        return subscribers.size();
    }
  private:
    struct Subscriber {
        void* ptr;
        EventHandlerSingature eventHandler;
        
        bool operator==(Subscriber const& other) const {
            return ptr == other.ptr;
        }
        bool operator<(Subscriber const& other) const {
            return ptr < other.ptr;
        }
    };
    std::set<Subscriber> subscribers;
};


/* Fast add event dispatchers to any object.
 * Any dispatcher can have any number of types
 * that can be sended to event handler function.
 *
 * Usage:
    SET_EVENT_DISPATCHERS(
        DISPATCHER(name1, type1, type2, ...);
        DISPATCHER(name2, type1, type2, ...);
    )

    SET_EVENT_DISPATCHERS(
        DISPATCHER(name1);
        DISPATCHER(name2);
    )
 *
 * Also added function GetDispatchers()
 * for get all of registered event dispatchers for this object.
 * Usage:
    object.GetDispatchers().name1.EmitEvent(type1, type2, ...);
    object.GetDispatchers().name1.Subscribe(subscriberPtr, FunctionHandlerPtr);
*/

#define SET_EVENT_DISPATCHERS(...)                                         \
private:                                                                   \
struct EventDispatchers { __VA_ARGS__ };                                   \
EventDispatchers eventDispatchers;                                         \
public:                                                                    \
EventDispatchers& GetDispatchers() { return eventDispatchers; }

#define DISPATCHER(NAME, ...) EventDispatcher<__VA_ARGS__> NAME


#endif // TESTGAME_EVENTDISPATCHER_HPP
