//
// Created by sancar koyunlu on 21/02/14.
//

#include "hazelcast/client/serialization/pimpl/SerializationConstants.h"

namespace hazelcast {
    namespace client {
        namespace serialization {
            namespace pimpl {

                int const SerializationConstants::CONSTANT_TYPE_PORTABLE = -1;
                int const SerializationConstants::CONSTANT_TYPE_DATA = -2;
                int const SerializationConstants::CONSTANT_TYPE_BYTE = -3;
                int const SerializationConstants::CONSTANT_TYPE_BOOLEAN = -4;
                int const SerializationConstants::CONSTANT_TYPE_CHAR = -5;
                int const SerializationConstants::CONSTANT_TYPE_SHORT = -6;
                int const SerializationConstants::CONSTANT_TYPE_INTEGER = -7;
                int const SerializationConstants::CONSTANT_TYPE_LONG = -8;
                int const SerializationConstants::CONSTANT_TYPE_FLOAT = -9;
                int const SerializationConstants::CONSTANT_TYPE_DOUBLE = -10;
                int const SerializationConstants::CONSTANT_TYPE_STRING = -11;
                int const SerializationConstants::CONSTANT_TYPE_BYTE_ARRAY = -12;
                int const SerializationConstants::CONSTANT_TYPE_CHAR_ARRAY = -13;
                int const SerializationConstants::CONSTANT_TYPE_SHORT_ARRAY = -14;
                int const SerializationConstants::CONSTANT_TYPE_INTEGER_ARRAY = -15;
                int const SerializationConstants::CONSTANT_TYPE_LONG_ARRAY = -16;
                int const SerializationConstants::CONSTANT_TYPE_FLOAT_ARRAY = -17;
                int const SerializationConstants::CONSTANT_TYPE_DOUBLE_ARRAY = -18;
                int const SerializationConstants::CONSTANT_SERIALIZERS_LENGTH = -(-19) - 1;
                // ------------------------------------------------------------
                int const SerializationConstants::DEFAULT_TYPE_CLASS = -19;
                int const SerializationConstants::DEFAULT_TYPE_DATE = -20;
                int const SerializationConstants::DEFAULT_TYPE_BIG_INTEGER = -21;
                int const SerializationConstants::DEFAULT_TYPE_BIG_DECIMAL = -22;
                int const SerializationConstants::DEFAULT_TYPE_OBJECT = -23;
                int const SerializationConstants::DEFAULT_TYPE_EXTERNALIZABLE = -24;
                int const SerializationConstants::DEFAULT_TYPE_ENUM = -25;

                SerializationConstants::SerializationConstants()
                :size(25)
                , typeIdNameVector(size) {
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_PORTABLE)] = "portable";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_DATA)] = "data";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_BYTE)] = "byte";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_BOOLEAN)] = "boolean";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_CHAR)] = "char";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_SHORT)] = "short";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_INTEGER)] = "integer";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_LONG)] = "long";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_FLOAT)] = "float";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_DOUBLE)] = "double";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_STRING)] = "string";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_BYTE_ARRAY)] = "byteArray";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_CHAR_ARRAY)] = "charArray";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_SHORT_ARRAY)] = "shortArray";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_INTEGER_ARRAY)] = "integerArray";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_LONG_ARRAY)] = "longArray";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_FLOAT_ARRAY)] = "floatArray";
                    typeIdNameVector[idToIndex(CONSTANT_TYPE_DOUBLE_ARRAY)] = "doubleArray";
                    typeIdNameVector[idToIndex(DEFAULT_TYPE_CLASS)] = "class";
                    typeIdNameVector[idToIndex(DEFAULT_TYPE_DATE)] = "date";
                    typeIdNameVector[idToIndex(DEFAULT_TYPE_BIG_INTEGER)] = "bigInteger";
                    typeIdNameVector[idToIndex(DEFAULT_TYPE_BIG_DECIMAL)] = "bigDecimal";
                    typeIdNameVector[idToIndex(DEFAULT_TYPE_OBJECT)] = "object";
                    typeIdNameVector[idToIndex(DEFAULT_TYPE_EXTERNALIZABLE)] = "externalizable";
                    typeIdNameVector[idToIndex(DEFAULT_TYPE_ENUM)] = "enum";
                }

                std::string SerializationConstants::typeIdToName(int typeId) {
                    int i = idToIndex(typeId);
                    if (i < 0 || i >= size)
                        return "custom";
                    return typeIdNameVector[i];
                }

                int SerializationConstants::idToIndex(int id) {
                    return id + size;
                }
            }
        }
    }
}
