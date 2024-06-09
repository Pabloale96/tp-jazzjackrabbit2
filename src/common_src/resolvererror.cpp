// Copyright 2024 Martin Di Paola

#include "../../include/common_src/catedra/resolvererror.h"

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>

ResolverError::ResolverError(int gai_errno): gai_errno(gai_errno) {}

const char* ResolverError::what() const noexcept { return gai_strerror(gai_errno); }

ResolverError::~ResolverError() {}
