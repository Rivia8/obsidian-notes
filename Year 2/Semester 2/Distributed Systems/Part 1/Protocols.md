12-04-2026 09:30

Tags: [[Distributed Systems]]

**"Protocols define sets of rules governing how two or more objects should interact with"**

They serve as the **specifications** rather than the **implementations** of a piece of technology.
	e.g. HTTP or HyperText Transport Protocol (HTTP), which provides a specification (i.e. vocabulary) that allows client applications to request resources from the Web servers and Web servers respond to these clients.

**Specification** dictates exactly what must happen and the **implementation** is the actual software that a developer writes to make the machine follow the rules.

## HTTP Protocol


| **HTTP Verbs** | Description                                                                                                                                                                                                                                   |
| -------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| HEAD           | Asks for the response identical to the one that would correspond to a GET request, but without the response body. This is useful for retrieving meta-information written in response headers, without having to transport the entire content. |
| GET            | Requests a representation of the specified resource. Requests using GET should only retrieve data and should have no other effect.                                                                                                            |
| POST           | Submits data to be processed (e.g., from an HTML form) to the identified resource.<br>The data is included in the body of the request. This may result in the creation of a new resource or the updates of existing resources or both.        |
| OPTIONS        | Returns a list of the commands supported by this particular server                                                                                                                                                                            |
| DELETE         | It is used to delete a resource. It may return the a representation of the removed resource.                                                                                                                                                  |

By following the HTTP protocol, Web servers are said to be **stateless.**

**Stateless** means that it has **zero memory of the past**. Every single time a client sends a request to a server, the server treats it as a brand-new interaction. Once the server sends the response back, it immediately drops the connection and forgets the client ever existed.

**HTTP** works like this and what this means is that for a successful interaction, it must contain 100% of the information the server needs to fulfil it, the server will not rely on anything you told it five minutes ago.

This may seem inefficient, but there are some major advantages to this:

1. Massive Scalability
	If a web server had to remember all these factors, it would run out RAM, by forgetting what happened instantly, the server instantly frees up resources to serve the next person.
2. Fau 

