#ifndef CLIENT_H
#define CLIENT_H

#include "connection.h"
/**
 * Client implementation.
 */
class Client final : public Connection {
    Q_OBJECT

public:
    /**
     * Constructor.
     * @param parent Pointer to the parent object initialization.
     */
    explicit Client(QObject* parent = nullptr);
};

#endif // CLIENT_H
