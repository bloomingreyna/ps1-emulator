#pragma once

#include <array>
#include <cstdint>

#include "components/cpu_vars.h"
#include "components/system_control_processor.h"
#include "instructions/opcode.h"
#include "utils/cpu_enums.h"
#include "utils/sysctlproc_enums.h"

class ps1;

class cpu
{
public:
    cpu();

    void tick();
    bool is_executing() const;

    bool coprocessor_usable(uint32_t coprocessor);
    void throw_exception(exception_type e);

    void prepare_load(uint32_t addr, std::size_t index, data_size load_size, data_signedness signedness);
    void prepare_load(uint32_t addr, std::size_t index, word_segment segment);
    void prepare_load_word(uint32_t addr, std::size_t index);
    void prepare_load_imm(uint32_t value, std::size_t index);
    void prepare_load_to_coprocessor(uint32_t addr, uint32_t coprocessor, std::size_t index);

    void store(uint32_t addr, uint32_t value, data_size store_size);
    void store(uint32_t addr, uint32_t value, word_segment segment);

    void prepare_branch(int32_t offset);
    void prepare_jump(uint32_t addr);

    uint32_t get_gpr(std::size_t index) const;
    uint32_t get_pc() const;
    uint32_t get_hi() const;
    uint32_t get_lo() const;

    void set_gpr(std::size_t index, uint32_t value);
    void set_pc(uint32_t value);
    void set_hi(uint32_t value);
    void set_lo(uint32_t value);

    uint32_t get_scp_cr(std::size_t index) const;
    void set_scp_cr(std::size_t index, uint32_t value);

    void set_problem_addr(uint32_t addr);
private:
    void fetch();
    void execute();
    void jump_to_exception_vec();
    void load_trigger();
    void load_logic();

    void finalize_load_operation(uint32_t data, std::size_t index, load_type ltype, load_target target);

    ps1& system;
    sysctlproc scp{};

    opcode o{};

    std::array<uint32_t, 32> gprs{};
    uint32_t pc{};
    uint32_t hi{};
    uint32_t lo{};

    cpu_load_vars load_vars{};
    cpu_pc_change_vars pc_change_vars{};

    bool executing{false};
    bool exception_thrown{false};

    uint32_t problematic_addr{};
};
