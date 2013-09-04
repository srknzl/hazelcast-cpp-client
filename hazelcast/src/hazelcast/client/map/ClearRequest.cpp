//
// Created by sancar koyunlu on 9/4/13.
// Copyright (c) 2013 hazelcast. All rights reserved.


#include "hazelcast/client/map/ClearRequest.h"
#include "PortableHook.h"
#include "PortableWriter.h"
#include "PortableReader.h"

namespace hazelcast {
    namespace client {
        namespace map {
            ClearRequest::ClearRequest(const std::string& name)
            :name(name) {

            };

            int ClearRequest::getFactoryId() const {
                return PortableHook::F_ID;
            }

            int ClearRequest::getClassId() const {
                return PortableHook::CLEAR;
            }


            void ClearRequest::writePortable(serialization::PortableWriter& writer) const {
                writer.writeUTF("n", name);
            };


            void ClearRequest::readPortable(serialization::PortableReader& reader) {
                name = reader.readUTF("n");
            };
        }
    }
}


