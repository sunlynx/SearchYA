#pragma once

#include <list>
#include <memory>
#include <atomic>
#include <grpc++/grpc++.h>

namespace grpc
{
	class Service;
}

//Represents a GRPC server in the eye of the process. provides the capability to initiate
//a server at a received end point (the server will listen for incoming calls at that address).
//also provides the capability to register services for up coming invocations at will.
//all services registrations must be done prior for the initialization and start of the server
//it self.
class GrpcServer
{
public:
	//Initiates a grpc server builder containing a single listening point.
	GrpcServer(const std::string& listeningPointAddress);
	~GrpcServer();
	//Received service is registered with grpc build server. the instance life cycle ownership
	//is also taken by the current GRPCService instance. it is mandatory to register the service
	//prior for the server starting point.
	void AddService(std::unique_ptr<grpc::Service> service);
	//Is the server starting point, notifying grpc framework with a request to initiate the underline
	//server.
	void Start();

private:
	grpc::ServerBuilder m_builder;
	std::list<std::unique_ptr<grpc::Service>> m_services;
	std::unique_ptr<grpc::Server> m_server;
	std::atomic_bool m_running;
};
