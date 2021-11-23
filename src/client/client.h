#ifndef CLIENT_H
#define CLIENT_H

#include "connection.h"

/// @brief Client implementation.
class Client final : public Connection
{
private:
    Q_OBJECT

public:
    /// @brief Constructor.
    /// @param parent Pointer to the parent object initialization.
    explicit Client(QObject* parent = nullptr);
};

#endif // CLIENT_H
