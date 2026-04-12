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

### Statelessness

By following the HTTP protocol, Web servers are said to be **stateless.**

**Stateless** means that it has **zero memory of the past**. Every single time a client sends a request to a server, the server treats it as a brand-new interaction. Once the server sends the response back, it immediately drops the connection and forgets the client ever existed.

**HTTP** works like this and what this means is that for a successful interaction, it must contain 100% of the information the server needs to fulfil it, the server will not rely on anything you told it five minutes ago.

This may seem inefficient, but there are some major advantages to this:

1. **Massive Scalability**
	If a web server had to remember all these factors, it would run out RAM, by forgetting what happened instantly, the server instantly frees up resources to serve the next person.
2. **Fault Tolerance**
	It allows for **No Single Point of Failure**. If a server fails with your transaction, it can be moved to another server. The new server doesn't need to know your history.

There is a bit of a caveat of *statelessness* within websites. 
In order to allow some functionality, state**full**ness is emulated on top of the statelessness logic. This is done outside the scope of the protocol.

This is done with things like browser **Cookies** or **Tokens**.

## Email

The way email works is more complicated than it seems.
The expectation of emails is that an email has to be in exactly **one place** at any **one time**.
	If its in two places it has been duplicated.
	If its in no places then its been 'lost in the system'

Because of the sensitive nature of the way that emails are handled, it cannot simply use a stateless protocol like HTTP (where the server acts like a vending machine and forgets instantly), instead it uses **SMTP (Simple Mail Transfer Protocol).**

### SMTP (Simple Mail Transfer Protocol)

SMTP is **connection based**. This means that client and server open a dedicated line of communication and keep it open until the entire transaction is finished. The server **must** remember the state of the conversation from one line to the next.


