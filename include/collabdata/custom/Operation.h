#pragma once

#include <sstream>

#include "OperationVisitor.h"

namespace collab {


/**
 * \brief
 * Interface that represents any operations on CollabData.
 *
 * Each operation on a CollabData has a unique ID for this data.
 *
 * \see OperationObserver
 * \see CollabData
 */
class Operation {
    protected:
        Operation() = default;
        Operation(const Operation& other) = default;
        Operation& operator=(const Operation& other) = default;
    public:
        virtual ~Operation() = default;


    public:

        /**
         * Get the type of this operation.
         * Returns 0 if not type set. (This may be an internal error.)
         *
         * \return ID of the operation's type.
         */
        virtual int getType() const = 0;

        /**
         * Serialize the operation data in internal packed format.
         *
         * \param buffer Where to place serialized data.
         * \return True if successfully serialized, otherwise, return false.
         */
        virtual bool serialize(std::stringstream& buffer) const = 0;

        /**
         *
         * Unserialize the operation from its internal packed format.
         *
         * \param buffer Where to place unserialized data.
         * \return True if successfully unserialized, otherwise, return false.
         */
        virtual bool unserialize(const std::stringstream& buffer) = 0;

        virtual void accept(OperationVisitor& visitor) = 0;
};


} // End namespace


