//
// Created by sancar koyunlu on 9/4/13.
// Copyright (c) 2013 hazelcast. All rights reserved.


#include "ContainsRequest.h"
#include "QueuePortableHook.h"
#include "PortableWriter.h"
#include "PortableReader.h"

namespace hazelcast {
    namespace client {
        namespace queue {
            ContainsRequest::ContainsRequest(const std::string& name, std::vector<serialization::Data>& dataList)
            :name(name)
            , dataList(dataList) {

            };

            int ContainsRequest::getFactoryId() const {
                return queue::QueuePortableHook::F_ID;
            }

            int ContainsRequest::getClassId() const {
                return queue::QueuePortableHook::CONTAINS;
            };


            void ContainsRequest::writePortable(serialization::PortableWriter& writer) const {
                writer.writeUTF("n", name);
                writer.writeInt("s", dataList.size());
                serialization::ObjectDataOutput& out = writer.getRawDataOutput();
                for (int i = 0; i < dataList.size(); ++i) {
                    dataList[i].writeData(out);
                }
            };

            void ContainsRequest::readPortable(serialization::PortableReader& reader) {
                name = reader.readUTF("n");
                int size = reader.readInt("s");
                dataList.resize(size);
                serialization::ObjectDataInput &in = reader.getRawDataInput();
                for (int i = 0; i < size; ++i) {
                    dataList[i].readData(in);
                }
            };
        }
    }
}

#endif //HAZELCAST_QUEUE_CONTAINS_REQUEST

