//
// Created by sancar koyunlu on 5/23/13.
// Copyright (c) 2013 hazelcast. All rights reserved.

#ifndef HAZELCAST_INVOCATION_SERVICE
#define HAZELCAST_INVOCATION_SERVICE

#include "hazelcast/util/HazelcastDll.h"
#include <boost/thread/future.hpp>

namespace hazelcast {
    namespace client {
        class Address;

        class ClientConfig;

        namespace serialization {
            namespace pimpl{
                class Data;
            }

        }
        namespace impl {
            class PortableRequest;

            class BaseEventHandler;
        }

        namespace connection {
            class Connection;

            class CallPromise;
        }
        namespace spi {

            class ClientContext;

            class HAZELCAST_API InvocationService {
            public:
                InvocationService(spi::ClientContext &clientContext);

                void start();

                boost::shared_future<serialization::pimpl::Data> invokeOnRandomTarget(const impl::PortableRequest *request);

                boost::shared_future<serialization::pimpl::Data> invokeOnKeyOwner(const impl::PortableRequest *request, int partitionId);

                boost::shared_future<serialization::pimpl::Data> invokeOnTarget(const impl::PortableRequest *request, const Address &target);

                boost::shared_future<serialization::pimpl::Data> invokeOnRandomTarget(const impl::PortableRequest *request, impl::BaseEventHandler *handler);

                boost::shared_future<serialization::pimpl::Data> invokeOnTarget(const impl::PortableRequest *request, impl::BaseEventHandler *handler, const Address &target);

                boost::shared_future<serialization::pimpl::Data> invokeOnKeyOwner(const impl::PortableRequest *request, impl::BaseEventHandler *handler, int partitionId);

                boost::shared_future<serialization::pimpl::Data> invokeOnConnection(const impl::PortableRequest *request, boost::shared_ptr<connection::Connection> connection);

                bool isRedoOperation() const;

                static const int RETRY_COUNT = 20;
            private :
                bool redoOperation;
                spi::ClientContext &clientContext;

                boost::shared_future<serialization::pimpl::Data> doSend(std::auto_ptr<const impl::PortableRequest>, std::auto_ptr<impl::BaseEventHandler>, boost::shared_ptr<connection::Connection>);


            };
        }
    }
}


#endif //__InvocationService_H_
