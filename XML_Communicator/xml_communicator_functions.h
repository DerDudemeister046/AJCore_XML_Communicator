#ifndef XML_COMMUNICATOR_FUNCTIONS_H
#define XML_COMMUNICATOR_FUNCTIONS_H

#include <QtCore>

class XML_Communicator_Functions
{
public:
    XML_Communicator_Functions();

    // Functions (Interpretation)
    QString processAJCoreID(QString line); // returns session ID of core session
};

#endif // XML_COMMUNICATOR_FUNCTIONS_H
