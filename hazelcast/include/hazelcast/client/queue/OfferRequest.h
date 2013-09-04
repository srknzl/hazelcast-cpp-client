//
// Created by sancar koyunlu on 5/23/13.
// Copyright (c) 2013 hazelcast. All rights reserved.
#ifndef HAZELCAST_QUEUE_OFFER_REQUEST
#define HAZELCAST_QUEUE_OFFER_REQUEST

#include "Portable.h"

namespace hazelcast {
    namespace client {
        namespace queue {
            class OfferRequest : public Portable {
            public:
                OfferRequest(const std::string& name, serialization::Data& data, long timeout);

                OfferRequest(const std::string& name, serialization::Data& data);

                int getFactoryId() const;

                int getClassId() const;

                void writePortable(serialization::PortableWriter& writer) const;

                void readPortable(serialization::PortableReader& reader);

            private:
                serialization::Data& data;
                std::string name;
                long timeoutInMillis;
            };
        }
    }
}

#endif //HAZELCAST_OFFER_REQUEST
