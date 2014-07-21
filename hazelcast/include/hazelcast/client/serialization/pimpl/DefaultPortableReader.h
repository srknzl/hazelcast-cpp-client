//
//  PortableReader.h
//  Server
//
//  Created by sancar koyunlu on 1/10/13.
//  Copyright (c) 2013 sancar koyunlu. All rights reserved.
//

#ifndef HAZELCAST_PORTABLE_READER
#define HAZELCAST_PORTABLE_READER

#include "hazelcast/client/serialization/ClassDefinition.h"
#include "hazelcast/client/serialization/pimpl/DataInput.h"
#include "hazelcast/client/serialization/ObjectDataInput.h"
#include <string>
#include <memory>

namespace hazelcast {
    namespace client {
        namespace serialization {

            class Portable;

            namespace pimpl {
                class SerializerHolder;

                class PortableContext;

                class HAZELCAST_API DefaultPortableReader {
                public:

                    DefaultPortableReader(PortableContext &portableContext, DataInput &input, boost::shared_ptr<ClassDefinition> cd);

                    int readInt(const char *fieldName);

                    long readLong(const char *fieldName);

                    bool readBoolean(const char *fieldName);

                    byte readByte(const char *fieldName);

                    char readChar(const char *fieldName);

                    double readDouble(const char *fieldName);

                    float readFloat(const char *fieldName);

                    short readShort(const char *fieldName);

                    std::string readUTF(const char *fieldName);

                    std::vector<byte> readByteArray(const char *fieldName);

                    std::vector<char> readCharArray(const char *fieldName);

                    std::vector<int> readIntArray(const char *fieldName);

                    std::vector<long> readLongArray(const char *fieldName);

                    std::vector<double> readDoubleArray(const char *fieldName);

                    std::vector<float> readFloatArray(const char *fieldName);

                    std::vector<short> readShortArray(const char *fieldName);

                    template<typename T>
                    boost::shared_ptr<T> readPortable(const char *fieldName) {
                        boost::shared_ptr<T> portable;
                        setPosition(fieldName);

                        bool isNull = dataInput.readBoolean();
                        if (isNull) {
                            return portable;
                        }
                        portable.reset(new T);
                        const FieldDefinition &fd = cd->get(fieldName);
                        int factoryId = fd.getFactoryId();
                        int classId = fd.getClassId();
                        read(dataInput, *portable, factoryId, classId);
                        return portable;
                    };

                    template<typename T>
                    std::vector< T > readPortableArray(const char *fieldName) {
                        std::vector< T > portables;
                        setPosition(fieldName);

                        const FieldDefinition &fd = cd->get(fieldName);
                        int factoryId = fd.getFactoryId();
                        int classId = fd.getClassId();
                        int len = dataInput.readInt();

                        portables.resize(len, T());
                        if (len > 0) {
                            int offset = dataInput.position();
                            for (int i = 0; i < len; i++) {
                                dataInput.position(offset + i * sizeof (int));
                                int start = dataInput.readInt();
                                dataInput.position(start);

                                read(dataInput, portables[i], factoryId, classId);
                            }
                        }
                        return portables;
                    };

                    ObjectDataInput &getRawDataInput();

                    void end();

                private:
                    int getPosition(const char *);

                    void setPosition(const char *);

                    void read(DataInput &dataInput, Portable &object, int factoryId, int classId);

                    SerializerHolder &serializerHolder;
                    DataInput &dataInput;
                    ObjectDataInput objectDataInput;
                    int const finalPosition;
                    int offset;
                    bool raw;
                    boost::shared_ptr<ClassDefinition> cd;

                };
            }

        }
    }
}
#endif /* HAZELCAST_PORTABLE_READER */

